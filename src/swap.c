/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/28 21:44:06 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/12/28 23:56:17 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stack *a)
{
	int	temp;

	if (a->size < 2)
		return ;
	temp = a->values[0];
	a->values[0] = a->values[1];
	a->values[1] = temp;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *b)
{
	int	temp;

	if (b->size < 2)
		return ;
	temp = b->values[0];
	b->values[0] = b->values[1];
	b->values[1] = temp;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	ft_putstr_fd("ss\n", 1);
}
