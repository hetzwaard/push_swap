/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/20 19:49:52 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/01/20 19:49:52 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push_swap(t_stack **a, t_stack **b)
{
	if (stack_len(*a) == 2)
		sa(a, false);
	else if (stack_len(*a) == 3)
		sort_three(a);
	else if (stack_len(*a) == 4 || stack_len(*a) == 5)
		sort_four_to_five(a, b);
	else
		radix_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	parser(argc, argv, &a);
	if (!stack_sorted(a))
		push_swap(&a, &b);
	stack_free(&a);
	return (0);
}
