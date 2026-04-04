/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adchebbi <adchebbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 07:21:40 by adchebbi          #+#    #+#             */
/*   Updated: 2026/03/31 09:00:52 by adchebbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_pos_of_max(t_stack *stack)
{
	int		max_index;
	int		max_pos;
	int		pos;

	max_index = stack->index;
	max_pos = 0;
	pos = 0;
	while (stack)
	{
		if (stack->index > max_index)
		{
			max_index = stack->index;
			max_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (max_pos);
}

static int	find_target_in_b(t_stack *b, int index)
{
	int		best_match;
	int		target_pos;
	t_stack	*tmp;

	best_match = -1;
	target_pos = 0;
	tmp = b;
	while (tmp)
	{
		if (tmp->index < index && tmp->index > best_match)
		{
			best_match = tmp->index;
			target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (best_match == -1)
		return (get_pos_of_max(b));
	return (target_pos);
}

void	assign_targets(t_stack *a, t_stack *b)
{
	while (a)
	{
		a->target_pos = find_target_in_b(b, a->index);
		a = a->next;
	}
}

int	find_target_in_a(t_stack *a, int index)
{
	int		best_match;
	int		target_pos;
	t_stack	*tmp;
	int		pos;

	best_match = INT_MAX;
	target_pos = 0;
	tmp = a;
	pos = 0;
	while (tmp)
	{
		if (tmp->index > index && tmp->index < best_match)
		{
			best_match = tmp->index;
			target_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	if (best_match == INT_MAX)
		return (get_min_pos(a));
	return (target_pos);
}
