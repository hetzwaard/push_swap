/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/20 14:00:51 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/01/20 14:00:51 by mahkilic      ########   odam.nl         */
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
	int		ret;

	a = NULL;
	b = NULL;
	arr = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2 && argv[1][0])
	{
		arr = ft_split_ps(argv[1], ' ');
		if (!arr)
			ft_free_arr(arr);
		ret = stack_init(&a, arr + 1);
	} 
	else
		ret = stack_init(&a, argv + 1);
	if (ret == 1)
		error_free(&a, arr);
	if (!stack_sorted(a) && ret == 0)
		push_swap(&a, &b);
	stack_free(&a);
	if (arr && argc == 2 && argv[1][0])
		ft_free_arr(arr);
	return (0);
}
