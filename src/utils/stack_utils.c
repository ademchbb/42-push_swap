/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adchebbi <adchebbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 07:15:43 by adchebbi          #+#    #+#             */
/*   Updated: 2026/03/26 07:30:40 by adchebbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->pos = 0;
	node->cost_a = 0;
	node->cost_b = 0;
	node->target_pos = 0;
	node->next = NULL;
	return (node);
}

void	add_back(t_stack **stack, t_stack *node)
{
	t_stack	*last;

	if (!*stack)
	{
		*stack = node;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = node;
}

int	get_min_pos(t_stack *stack)
{
	int		min_index;
	int		min_pos;
	int		pos;

	min_index = stack->index;
	min_pos = 0;
	pos = 0;
	while (stack)
	{
		if (stack->index < min_index)
		{
			min_index = stack->index;
			min_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (min_pos);
}
