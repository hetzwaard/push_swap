/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/30 17:34:48 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/01/14 21:54:16 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	get_index(t_stack *stack, t_stack *node)
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
	t_stack	*smallest;
	int		index;

	while (stack_len(*a) > 3)
	{
		smallest = find_lowest(*a);
		index = get_index(*a, smallest);
		if (index <= stack_len(*a) / 2)
			while (*a != smallest)
				ra(a, false);
		else
			while (*a != smallest)
				rra(a, false);
		pb(b, a, false);
	}
	sort_three(a);
	while (*b)
		pa(a, b, false);
}
