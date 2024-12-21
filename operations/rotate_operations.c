/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_operations.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/21 15:52:41 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/12/21 15:52:41 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stack *a)
{
	int	temp;
	int	i;

	if (a->size > 1)
	{
		temp = a->arr[0];
		i = 0;
		while (i < a->size - 1)
		{
			a->arr[i] = a->arr[i + 1];
			i++;
		}
		a->arr[a->size - 1] = temp;
		write(1, "ra\n", 3);
	}
}

void	rb(t_stack *b)
{
	int	temp;
	int	i;

	if (b->size > 1)
	{
		temp = b->arr[0];
		i = 0;
		while (i < b->size - 1)
		{
			b->arr[i] = b->arr[i + 1];
			i++;
		}
		b->arr[b->size - 1] = temp;
		write(1, "rb\n", 3);
	}
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}
