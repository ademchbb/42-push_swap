/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adchebbi <adchebbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 07:28:50 by adchebbi          #+#    #+#             */
/*   Updated: 2026/03/26 07:30:08 by adchebbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_all_to_b(t_stack **a, t_stack **b)
{
	pb(a, b);
	pb(a, b);
	while (stack_size(*a) > 3)
	{
		assign_positions(*a);
		assign_positions(*b);
		assign_targets(*a, *b);
		calculate_costs(*a, *b);
		do_cheapest(a, b);
	}
}

static void	push_all_to_a(t_stack **a, t_stack **b)
{
	int	target_pos;
	int	size;

	while (*b)
	{
		target_pos = find_target_in_a(*a, (*b)->index);
		size = stack_size(*a);
		if (target_pos <= size / 2)
			while (target_pos-- > 0)
				ra(a);
		else
			while (target_pos++ < size)
				rra(a);
		pa(a, b);
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;
	int	min_pos;

	size = stack_size(*a);
	if (size <= 1 || is_sorted(*a))
		return ;
	if (size == 2)
		return (sort_two(a));
	if (size == 3)
		return (sort_three(a));
	push_all_to_b(a, b);
	sort_three(a);
	push_all_to_a(a, b);
	min_pos = get_min_pos(*a);
	size = stack_size(*a);
	if (min_pos <= size / 2)
		while (min_pos-- > 0)
			ra(a);
	else
		while (min_pos++ < size)
			rra(a);
}
