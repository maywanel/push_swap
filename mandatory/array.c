/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mes <moel-mes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 22:06:50 by moel-mes          #+#    #+#             */
/*   Updated: 2024/12/27 22:06:51 by moel-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_int_tab(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	return (arr);
}

int	*stack_to_array(t_stack_node *stack)
{
	int	*arr;
	int	i;
	int	size;

	size = stack_len(stack);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (stack)
	{
		arr[i] = stack->value;
		i++;
		stack = stack->next;
	}
	return (sort_int_tab(arr, size));
}
