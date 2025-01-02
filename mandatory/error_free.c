/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mes <moel-mes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 22:06:56 by moel-mes          #+#    #+#             */
/*   Updated: 2024/12/27 22:06:57 by moel-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_matrix(char **argv)
{
	int	i;

	i = -1;
	if (!argv || !*argv)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (NULL == stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	error_free(t_stack_node **a, char **argv, bool flag)
{
	free_stack(a);
	if (flag)
		free_matrix(argv);
	ft_putstr("Error");
	exit(1);
}

int	error_syntax(char *str_nbr)
{
	if (!(*str_nbr == '+' || *str_nbr == '-' || (*str_nbr >= '0'
				&& *str_nbr <= '9')))
		return (1);
	if ((*str_nbr == '+' || *str_nbr == '-') && !(str_nbr[1] >= '0'
			&& str_nbr[1] <= '9'))
		return (1);
	while (*++str_nbr)
	{
		if (!(*str_nbr >= '0' && *str_nbr <= '9'))
			return (1);
	}
	return (0);
}

int	error_repetition(t_stack_node *a, int nbr)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}
