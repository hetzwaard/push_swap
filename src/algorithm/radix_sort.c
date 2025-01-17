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

static void	index_stack(t_stack *stack)
{
	long	*arr;
	int		size;
	int		i;

	size = stack_len(stack);
	arr = malloc(sizeof(long) * size);
	if (!arr)
		return ;
	fill_array(stack, arr);
	quicksort(arr, 0, size - 1);
	while (stack)
	{
		i = 0;
		while (arr[i] != stack->value)
			i++;
		stack->value = i;
		stack = stack->next;
	}
	free(arr);
}

static void	fill_array(t_stack *stack, long *arr)
{
	int	i;

	i = 0;
	while (stack)
	{
		arr[i++] = stack->value;
		stack = stack->next;
	}
}

static void	quicksort(long *arr, int low, int high)
{
	int		i;
	int		j;
	int		pivot;
	long	temp;

	if (low >= high)
		return ;
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
			temp = arr[i];
			arr[i++] = arr[j];
			arr[j--] = temp;
		}
	}
	quicksort(arr, low, j);
	quicksort(arr, i, high);
}

static void	radix_sort_step(t_stack **a, t_stack **b, int bit)
{
	int	size;

	size = stack_len(*a);
	while (size--)
	{
		if (((*a)->value >> bit) & 1)
			ra(a, false);
		else
			pb(b, a, false);
	}
	size = stack_len(*b);
	while (size--)
		pa(a, b, false);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	bit_size;
	int	bit;
	int	size;

	index_stack(*a);
	size = stack_len(*a);
	bit_size = 0;
	while ((size >> bit_size) > 0)
		bit_size++;
	bit = 0;
	while (bit < bit_size)
		radix_sort_step(a, b, bit++);
}
