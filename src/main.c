/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/21 15:46:44 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/12/21 15:46:44 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_stacks(t_stack *a, t_stack *b)
{
	if (a->arr)
		free(a->arr);
	if (b)
	{
		if (b->arr)
			free(b->arr);
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	a.arr = NULL;
	b.arr = NULL;
	validate_and_fill_stack(&a, argc, argv);
	b.arr = malloc(sizeof(int) * a.size);
	if (!b.arr)
		error_exit(&a, &b);
	b.size = 0;
	if (!is_sorted(&a))
		sort_stack(&a, &b);
	free_stacks(&a, &b);
	return (0);
}
