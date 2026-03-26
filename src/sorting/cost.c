/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adchebbi <adchebbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 07:23:56 by adchebbi          #+#    #+#             */
/*   Updated: 2026/03/26 07:25:00 by adchebbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_positions(t_stack *stack)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		stack->pos = pos;
		pos++;
		stack = stack->next;
	}
}

void	calculate_costs(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	while (a)
	{
		if (a->pos <= size_a / 2)
			a->cost_a = a->pos;
		else
			a->cost_a = a->pos - size_a;
		if (a->target_pos <= size_b / 2)
			a->cost_b = a->target_pos;
		else
			a->cost_b = a->target_pos - size_b;
		a = a->next;
	}
}
