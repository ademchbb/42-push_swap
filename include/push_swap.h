/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adchebbi <adchebbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 06:22:50 by adchebbi          #+#    #+#             */
/*   Updated: 2026/03/26 07:34:35 by adchebbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				cost_a;
	int				cost_b;
	int				target_pos;
	struct s_stack	*next;
}	t_stack;

/* parsing */
t_stack	*parse_args(int argc, char **argv);
long	ft_atol(const char *str);

/* stack utils */
t_stack	*new_node(int value);
void	add_back(t_stack **stack, t_stack *node);
int		get_min_pos(t_stack *stack);

/* utils */
void	free_stack(t_stack **stack);
void	error_exit(t_stack **a, t_stack **b);
t_stack	*free_and_return(t_stack *a, char **args, int argc);
int		stack_size(t_stack *stack);
int		is_sorted(t_stack *stack);

/* operations */
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/* indexing */
void	index_stack(t_stack *stack);

/* sorting */
void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
void	sort_stack(t_stack **a, t_stack **b);

/* cost & targets */
void	assign_positions(t_stack *stack);
void	assign_targets(t_stack *a, t_stack *b);
void	calculate_costs(t_stack *a, t_stack *b);
void	do_cheapest(t_stack **a, t_stack **b);
int		find_target_in_a(t_stack *a, int index);

#endif