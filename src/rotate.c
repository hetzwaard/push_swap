/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/28 21:44:51 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/12/28 23:55:36 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stack *a)
{
	int	temp;
	int	i;

	if (a->size < 2)
		return ;
	temp = a->values[0];
	i = 0;
	while (i < a->size - 1)
	{
		a->values[i] = a->values[i + 1];
		i++;
	}
	a->values[a->size - 1] = temp;
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *b)
{
	int	temp;
	int	i;

	if (b->size < 2)
		return ;
	temp = b->values[0];
	i = 0;
	while (i < b->size - 1)
	{
		b->values[i] = b->values[i + 1];
		i++;
	}
	b->values[b->size - 1] = temp;
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	ft_putstr_fd("rr\n", 1);
}
