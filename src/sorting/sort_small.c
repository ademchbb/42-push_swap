/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adchebbi <adchebbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 07:19:41 by adchebbi          #+#    #+#             */
/*   Updated: 2026/03/27 21:46:10 by adchebbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->index > (*a)->next->index)
		sa(a);
}

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first > second && first > third)
	{
		ra(a);
		if ((*a)->index > (*a)->next->index)
			sa(a);
	}
	else if (second > first && second > third)
	{
		rra(a);
		if ((*a)->index > (*a)->next->index)
			sa(a);
	}
	else
	{
		if (first > second)
			sa(a);
	}
}
