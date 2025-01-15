/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/15 14:10:59 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/01/15 14:10:59 by mahkilic      ########   odam.nl         */
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
	char	**arr;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2 && argv[1][0])
	{
		arr = ft_ps_split(argv[1], ' ');
		stack_init(&a, arr + 1);
		ft_free_arr(arr);
	}
	else
		stack_init(&a, argv + 1);
	if (!stack_sorted(a))
		push_swap(&a, &b);
	stack_free(&a);
	return (0);
}
