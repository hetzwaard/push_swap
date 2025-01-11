/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/10 19:55:18 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/01/12 00:50:01 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	move_stack_b(t_stack **a, t_stack **b, int bit_size, int j)
{
	int	b_size;

	b_size = stack_len(*b);
	while (b_size-- && j <= bit_size && !stack_sorted(*a))
	{
		if (((*b)->value >> j) & 1)
			pa(a, b, false);
		else
			rb(b, false);
	}
}

static void	move_stack_a(t_stack **a, t_stack **b, int j)
{
	int	size;

	size = stack_len(*a);
	while (size-- && !stack_sorted(*a))
	{
		if (((*a)->value >> j) & 1)
			ra(a, false);
		else
			pb(b, a, false);
	}
}

static void	radix_sort_stack_b(t_stack **a, t_stack **b, int bit_size, int j)
{
	move_stack_b(a, b, bit_size, j);
	if (stack_sorted(*a))
	{
		while (*b)
			pa(a, b, false);
	}
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	j;
	int	bit_size;
	int	size;

	index_stack_values(*a);
	bit_size = 0;
	size = stack_len(*a);
	while (size > 1 && ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		move_stack_a(a, b, j);
		radix_sort_stack_b(a, b, bit_size, j + 1);
	}
	while (*b)
		pa(a, b, false);
}
