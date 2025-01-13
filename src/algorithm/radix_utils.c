/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/12 00:44:03 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/01/12 00:46:43 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	fill_array_from_stack(t_stack *stack, long *arr)
{
	int	i;

	i = 0;
	while (stack)
	{
		arr[i++] = stack->value;
		stack = stack->next;
	}
}

static int	partition(long *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[(low + high) / 2];
	i = low;
	j = high;
	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			ft_swap_long(&arr[i], &arr[j]);
			i++;
			j--;
		}
	}
	return (i);
}

static void	quicksort_long(long *arr, int low, int high)
{
	int	index;

	if (low < high)
	{
		index = partition(arr, low, high);
		quicksort_long(arr, low, index - 1);
		quicksort_long(arr, index, high);
	}
}

static void	assign_ranks_to_stack(t_stack *stack, long *arr, int size)
{
	int	rank;

	while (stack)
	{
		rank = 0;
		while (rank < size && arr[rank] != stack->value)
			rank++;
		stack->value = rank;
		stack = stack->next;
	}
}

void	index_stack_values(t_stack *stack)
{
	long	*arr;
	int		size;

	size = stack_len(stack);
	arr = malloc(sizeof(long) * size);
	if (!arr)
		return ;
	fill_array_from_stack(stack, arr);
	quicksort_long(arr, 0, size - 1);
	assign_ranks_to_stack(stack, arr, size);
	free(arr);
}
