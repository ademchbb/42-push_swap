/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adchebbi <adchebbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 07:27:05 by adchebbi          #+#    #+#             */
/*   Updated: 2026/03/31 09:36:40 by adchebbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	abs_val(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	execute_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rr(a, b);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(a, b);
		cost_a++;
		cost_b++;
	}
	while (cost_a > 0 && cost_a--)
		ra(a);
	while (cost_a < 0 && cost_a++)
		rra(a);
	while (cost_b > 0 && cost_b--)
		rb(b);
	while (cost_b < 0 && cost_b++)
		rrb(b);
	pb(a, b);
}

static int	total_cost(int cost_a, int cost_b)
{
	if (cost_a >= 0 && cost_b >= 0)
	{
		if (cost_a > cost_b)
			return (cost_a);
		return (cost_b);
	}
	if (cost_a < 0 && cost_b < 0)
	{
		if (abs_val(cost_a) > abs_val(cost_b))
			return (abs_val(cost_a));
		return (abs_val(cost_b));
	}
	return (abs_val(cost_a) + abs_val(cost_b));
}

void	do_cheapest(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		cheapest;
	int		best_a;
	int		best_b;

	tmp = *a;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (total_cost(tmp->cost_a, tmp->cost_b) < cheapest)
		{
			cheapest = total_cost(tmp->cost_a, tmp->cost_b);
			best_a = tmp->cost_a;
			best_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	execute_move(a, b, best_a, best_b);
}
