/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_a_to_b.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/30 18:42:20 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/01/02 01:13:34 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	set_current(t_stack *stack)
{
	int	i;
	int	centerline;

	i = 0;
	if (stack == NULL)
		return ;
	centerline = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i < centerline)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

void	set_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_price = a->current;
		if (!(a->above_median))
			a->push_price = len_a - (a->current);
		if (a->target->above_median)
			a->push_price += a->target->current;
		else
			a->push_price += len_b - (a->target->current);
		a = a->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	long	best_value;
	t_stack	*best_node;

	if (stack == NULL)
		return ;
	best_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_price < best_value)
		{
			best_value = stack->push_price;
			best_node = stack;
		}
		stack = stack->next;
	}
	best_node->cheapest = true;
}

static void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target;
	long	best_index;

	while (a)
	{
		best_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->value > a->value && current_b->value < best_index)
			{
				best_index = current_b->value;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_index == LONG_MIN)
			a->target = find_smallest(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	set_a_to_b(t_stack *a, t_stack *b)
{
	set_current(a);
	set_current(b);
	set_target_a(a, b);
	set_price(a, b);
	set_cheapest(a);
}
