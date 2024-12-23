/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/21 15:28:48 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/12/21 15:28:48 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	is_duplicated(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->arr[i] == stack->arr[j])
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	error_exit(t_stack *a, t_stack *b)
{
	write(2, "Error\n", 6);
	free_stacks(a, b);
	exit(EXIT_FAILURE);
}

void	free_stacks(t_stack *a, t_stack *b)
{
	if (a->arr)
		free(a->arr);
	if (b->arr)
		free(b->arr);
}

void	validate_and_fill_stack(t_stack *stack, int argc, char **argv)
{
	int	i;

	stack->size = argc - 1;
	stack->arr = malloc(sizeof(int) * stack->size);
	if (!stack->arr)
		error_exit(stack, NULL);
	i = 0;
	while (i < stack->size)
	{
		stack->arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 1;
	while (i < stack->size)
	{
		if (stack->arr[i - 1] > stack->arr[i])
			return (0);
		i++;
	}
	return (1);
}
