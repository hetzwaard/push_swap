/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate_operations.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/21 15:52:57 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/12/21 15:52:57 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_stack *a)
{
	int	temp;
	int	i;

	if (a->size > 1)
	{
		temp = a->arr[a->size - 1];
		i = a->size - 1;
		while (i > 0)
		{
			a->arr[i] = a->arr[i - 1];
			i--;
		}
		a->arr[0] = temp;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack *b)
{
	int	temp;
	int	i;

	if (b->size > 1)
	{
		temp = b->arr[b->size - 1];
		i = b->size - 1;
		while (i > 0)
		{
			b->arr[i] = b->arr[i - 1];
			i--;
		}
		b->arr[0] = temp;
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
