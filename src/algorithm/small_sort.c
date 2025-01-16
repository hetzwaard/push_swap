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
