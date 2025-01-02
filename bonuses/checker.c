/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mes <moel-mes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:14:54 by moel-mes          #+#    #+#             */
/*   Updated: 2024/12/29 10:22:58 by moel-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_all(char *operation, t_stack_node **a, t_stack_node **b)
{
  while (operation)
  {
    free(operation);
    operation = get_next_line(0);
  }
  free_stack(a);
  free_stack(b);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return (1);
}

void	apply_moves(t_stack_node **a, t_stack_node **b, char *operation)
{
	if (!ft_strncmp(operation, "pa\n", 3))
		pa(a, b, true);
	else if (!ft_strncmp(operation, "pb\n", 3))
		pb(b, a, true);
	else if (!ft_strncmp(operation, "sa\n", 3))
		sa(a, true);
	else if (!ft_strncmp(operation, "sb\n", 3))
		sb(b, true);
	else if (!ft_strncmp(operation, "ss\n", 3))
		ss(b, a, true);
	else if (!ft_strncmp(operation, "ra\n", 3))
		ra(a, true);
	else if (!ft_strncmp(operation, "rb\n", 3))
		rb(b, true);
	else if (!ft_strncmp(operation, "rr\n", 3))
		rr(a, b, true);
	else if (!ft_strncmp(operation, "rra\n", 4))
		rra(a, true);
	else if (!ft_strncmp(operation, "rrb\n", 4))
		rrb(b, true);
	else if (!ft_strncmp(operation, "rrr\n", 4))
		rrr(a, b, true);
	else
		(free_all(operation, a, b), ft_putstr("Error"), exit(1));
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*operation;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	stack_init(&a, av + 1, ac == 2);
	if (!a)
		ft_putstr("Error\n");
	operation = get_next_line(0);
	while (operation)
	{
		apply_moves(&a, &b, operation);
		free(operation);
		operation = get_next_line(0);
	}
	if (stack_sorted(a) && !b)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	(free_stack(&a), free_stack(&b));
}
