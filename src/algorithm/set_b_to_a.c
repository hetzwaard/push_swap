/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_b_to_a.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/02 00:38:54 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/01/02 00:45:30 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target;
	long	best_index;

	while (b)
	{
		best_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < best_index)
			{
				best_index = current_a->value;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_index == LONG_MAX)
			b->target = find_smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	set_b_to_a(t_stack *a, t_stack *b)
{
	set_current(a);
	set_current(b);
	set_target_b(a, b);
}
