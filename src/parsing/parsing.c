/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adchebbi <adchebbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 07:08:46 by adchebbi          #+#    #+#             */
/*   Updated: 2026/03/26 07:16:16 by adchebbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	has_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int	process_arg(t_stack **a, char *arg)
{
	long	value;

	if (!is_valid_number(arg))
		return (0);
	value = ft_atol(arg);
	if (value > INT_MAX || value < INT_MIN)
		return (0);
	if (has_duplicate(*a, (int)value))
		return (0);
	add_back(a, new_node((int)value));
	return (1);
}

t_stack	*parse_args(int argc, char **argv)
{
	t_stack	*a;
	char	**args;
	int		i;

	a = NULL;
	args = argv + 1;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	if (!args || !args[0])
		return (NULL);
	i = -1;
	while (args[++i])
	{
		if (!process_arg(&a, args[i]))
			return (free_and_return(a, args, argc));
	}
	if (argc == 2)
		free_tab(args);
	return (a);
}
