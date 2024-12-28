/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/28 16:23:40 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/12/29 00:17:20 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	if (a->size == 3)
		sort_three(a);
	else if (a->size == 5)
		sort_five(a, b);
}

int	main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	char **nums;
	int i;

	if (argc < 2)
		return (0);
	nums = parse_input(argc, argv);
	a.size = 0;
	while (nums[a.size])
		a.size++;
	a.values = malloc(sizeof(int) * a.size);
	if (!a.values)
		print_error();
	i = 0;
	while (i < a.size)
	{
		a.values[i] = ft_atoi(nums[i]);
		i++;
	}
	free_split(nums);
	b.size = 0;
	b.values = malloc(sizeof(int) * a.size);
	if (!b.values)
	{
		free(a.values);
		print_error();
	}
	push_swap(&a, &b);
	free(a.values);
	free(b.values);
	return (0);
}