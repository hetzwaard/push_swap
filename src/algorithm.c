/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/21 15:33:39 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/12/21 15:33:39 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	find_min(t_stack *stack)
{
	int	i;
	int	min;
	int	min_index;

	i = 0;
	min = stack->arr[0];
	min_index = 0;
	while (i < stack->size)
	{
		if (stack->arr[i] < min)
		{
			min = stack->arr[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

static void	move_to_b(t_stack *a, t_stack *b, int chunk_size)
{
	int	i;
	int	min;
	int	max;
	int	pushed;

	min = a->arr[find_min(a)];
	max = min + chunk_size;
	pushed = 0;
	while (pushed < chunk_size && a->size > 0)
	{
		i = 0;
		while (i < a->size)
		{
			if (a->arr[i] >= min && a->arr[i] < max)
			{
				while (i > 0)
				{
					ra(a);
					i--;
				}
				pb(a, b);
				pushed++;
				break ;
			}
			i++;
		}
		if (i == a->size)
		{
			min = max;
			max += chunk_size;
		}
	}
}

static void	move_back_to_a(t_stack *a, t_stack *b)
{
	int	i;
	int	max;
	int	max_pos;

	while (b->size > 0)
	{
		i = 0;
		max = b->arr[0];
		max_pos = 0;
		while (i < b->size)
		{
			if (b->arr[i] > max)
			{
				max = b->arr[i];
				max_pos = i;
			}
			i++;
		}
		while (max_pos > 0)
		{
			rb(b);
			max_pos--;
		}
		pa(a, b);
	}
}

void	sort_stack(t_stack *a, t_stack *b)
{
	int chunk_size;

	if (a->size <= 3)
	{
		if (a->size == 2 && a->arr[0] > a->arr[1])
			sa(a);
		return ;
	}
	if (a->size <= 100)
		chunk_size = 20;
	else
		chunk_size = 45;
	while (a->size > 0)
		move_to_b(a, b, chunk_size);
	move_back_to_a(a, b);
}