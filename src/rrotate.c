/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rrotate.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/28 21:45:35 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/12/28 23:56:59 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_stack *a)
{
	int	temp;
	int	i;

	if (a->size < 2)
		return ;
	temp = a->values[a->size - 1];
	i = a->size - 1;
	while (i > 0)
	{
		a->values[i] = a->values[i - 1];
		i--;
	}
	a->values[0] = temp;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *b)
{
	int	temp;
	int	i;

	if (b->size < 2)
		return ;
	temp = b->values[b->size - 1];
	i = b->size - 1;
	while (i > 0)
	{
		b->values[i] = b->values[i - 1];
		i--;
	}
	b->values[0] = temp;
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	ft_putstr_fd("rrr\n", 1);
}
