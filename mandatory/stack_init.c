/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mes <moel-mes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 22:08:16 by moel-mes          #+#    #+#             */
/*   Updated: 2024/12/27 22:22:19 by moel-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo(t_stack_node **a, t_stack_node **b, int median, int q1)
{
	while (stack_len(*a) > 3)
	{
		if (bigger_than_median(*a, median))
		{
			while (stack_len(*a) > 3)
				pb(b, a, false);
			break ;
		}
		if ((*a)->value < median)
		{
			pb(b, a, false);
			if ((*b)->value < q1)
				rb(b, false);
		}
		else
			ra(a, false);
	}
	tiny_sort(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
}

int	bigger_than_median(t_stack_node *a, int median)
{
	while (a)
	{
		if (a->value < median)
			return (0);
		a = a->next;
	}
	return (1);
}

static long	ft_atol(const char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

void	stack_init(t_stack_node **a, char **av, bool flag)
{
	long	nbr;
	int		i;

	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			error_free(a, av, flag);
		nbr = ft_atol(av[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			error_free(a, av, flag);
		if (error_repetition(*a, (int)nbr))
			error_free(a, av, flag);
		append_node(a, (int)nbr);
		++i;
	}
	if (flag)
		free_matrix(av);
}
