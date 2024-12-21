/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_operations.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/21 15:51:55 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/12/21 15:51:55 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stack *a)
{
	int	temp;

	if (a->size > 1)
	{
		temp = a->arr[0];
		a->arr[0] = a->arr[1];
		a->arr[1] = temp;
		write(1, "sa\n", 3);
	}
}

void	sb(t_stack *b)
{
	int	temp;

	if (b->size > 1)
	{
		temp = b->arr[0];
		b->arr[0] = b->arr[1];
		b->arr[1] = temp;
		write(1, "sb\n", 3);
	}
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}
