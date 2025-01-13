/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mes <moel-mes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 22:07:00 by moel-mes          #+#    #+#             */
/*   Updated: 2024/12/27 22:07:01 by moel-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *ft_args(char **av, int ac)
{
  char  *args;
  int   i;

  i = 0;
  args = NULL;
  while (i < ac - 1)
  {
    args = ft_strjoin(args, av[i]);
    args = ft_strjoin(args, " ");
    if (!args)
      return (NULL);
    i++;
  }
  i = 0;
  while (args[i])
  {
    if (args[i] != ' ')
      return (args);
    i++;
  }
  free(args);
  return (NULL);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
  char *s;
  char **args;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
  s = ft_args(argv + 1, argc);
  if (!s)
  {
    ft_putstr("Error");
    free(s);
    exit(1);
  }
	args = ft_split(s, ' ');
	stack_init(&a, args + 1, true);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			tiny_sort(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
	return (0);
}

