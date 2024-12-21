/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_operations.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/21 15:52:18 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/12/21 15:52:18 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	int	i;

	if (b->size > 0)
	{
		a->size++;
		i = a->size - 1;
		while (i > 0)
		{
			a->arr[i] = a->arr[i - 1];
			i--;
		}
		a->arr[0] = b->arr[0];
		i = 0;
		while (i < b->size - 1)
		{
			b->arr[i] = b->arr[i + 1];
			i++;
		}
		b->size--;
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack *a, t_stack *b)
{
	int	i;

	if (a->size > 0)
	{
		b->size++;
		i = b->size - 1;
		while (i > 0)
		{
			b->arr[i] = b->arr[i - 1];
			i--;
		}
		b->arr[0] = a->arr[0];
		i = 0;
		while (i < a->size - 1)
		{
			a->arr[i] = a->arr[i + 1];
			i++;
		}
		a->size--;
		write(1, "pb\n", 3);
	}
}
