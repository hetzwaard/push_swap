/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/30 17:34:48 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/01/16 15:12:17 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static t_stack	*find_highest(t_stack *stack)
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

static t_stack	*find_lowest(t_stack *stack)
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

static int	find_index(t_stack *stack, t_stack *node)
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

void	sort_three(t_stack **a)
{
	t_stack	*highest_node;

	if (stack_sorted(*a))
		return ;
	highest_node = find_highest(*a);
	if (*a == highest_node)
		ra(a, false);
	else if ((*a)->next == highest_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	sort_four_to_five(t_stack **a, t_stack **b)
{
	t_stack	*lowest;
	int		index;

	while (stack_len(*a) > 3)
	{
		lowest = find_lowest(*a);
		index = find_index(*a, lowest);
		if (index <= 2)
			while (*a != lowest)
				ra(a, false);
		else
			while (*a != lowest)
				rra(a, false);
		pb(b, a, false);
	}
	sort_three(a);
	while (*b)
		pa(a, b, false);
}
