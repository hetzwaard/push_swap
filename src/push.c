/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/28 21:40:13 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/12/28 23:55:12 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	int	i;

	if (b->size == 0)
		return ;
	i = a->size;
	while (i > 0)
	{
		a->values[i] = a->values[i - 1];
		i--;
	}
	a->values[0] = b->values[0];
	i = 0;
	while (i < b->size - 1)
	{
		b->values[i] = b->values[i + 1];
		i++;
	}
	a->size++;
	b->size--;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	int	i;

	if (a->size == 0)
		return ;
	i = b->size;
	while (i > 0)
	{
		b->values[i] = b->values[i - 1];
		i--;
	}
	b->values[0] = a->values[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->values[i] = a->values[i + 1];
		i++;
	}
	b->size++;
	a->size--;
	ft_putstr_fd("pb\n", 1);
}
