/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_five.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/28 21:47:51 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/12/28 23:52:11 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_smallest(t_stack *stack)
{
	int	smallest;
	int	index;
	int	i;

	smallest = stack->values[0];
	index = 0;
	i = 1;
	while (i < stack->size)
	{
		if (stack->values[i] < smallest)
		{
			smallest = stack->values[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	push_smallest_to_b(t_stack *a, t_stack *b)
{
	int	smallest_index;

	smallest_index = find_smallest(a);
	if (smallest_index <= a->size / 2)
	{
		while (smallest_index--)
			ra(a);
	}
	else
	{
		while (smallest_index++ < a->size)
			rra(a);
	}
	pb(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		push_smallest_to_b(a, b);
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}
