/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/10 19:55:18 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/01/10 19:55:18 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	radix_sort(t_stack **a, t_stack **b)
{
	int		max_bits;
	int		i;
	int		j;
	int		size;
	t_stack	*current;

	size = stack_len(*a);
	max_bits = 0;
	while ((size - 1) >> max_bits != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			current = *a;
			if (((current->value >> i) & 1) == 1)
				ra(a, false);
			else
				pb(b, a, false);
			j++;
		}
		while (*b)
			pa(a, b, false);
		i++;
	}
}
