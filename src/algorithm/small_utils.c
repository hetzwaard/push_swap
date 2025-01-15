/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/30 15:27:48 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/01/15 10:34:10 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*find_last_node(t_stack *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

t_stack	*find_highest(t_stack *stack)
{
	long	highest;
	t_stack	*highest_node;

	if (stack == NULL)
		return (NULL);
	highest = LONG_MIN;
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

t_stack	*find_lowest(t_stack *stack)
{
	long	lowest;
	t_stack	*lowest_node;

	if (stack == NULL)
		return (NULL);
	lowest = LONG_MAX;
	while (stack)
	{
		if (stack->value < lowest)
		{
			lowest = stack->value;
			lowest_node = stack;
		}
		stack = stack->next;
	}
	return (lowest_node);
}

int	find_index(t_stack *stack, t_stack *node)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack == node)
			return (index);
		stack = stack->next;
		index++;
	}
	return (-1);
}
