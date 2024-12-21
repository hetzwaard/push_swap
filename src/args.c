/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   args.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/21 15:33:39 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/12/21 15:33:39 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_valid(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	validate_and_fill_stack(t_stack *a, int argc, char **argv)
{
	int	i;

	a->size = argc - 1;
	a->arr = malloc(sizeof(int) * a->size);
	if (!a->arr)
		error_exit(a, 0);
	i = 0;
	while (i < a->size)
	{
		if (!is_valid(argv[i + 1]) || !argv[i + 1][0])
			error_exit(a, NULL);
		a->arr[i] = ft_atoi(argv[i + 1]);
		if (a->arr[i] > INT_MAX || a->arr[i] < INT_MIN)
			error_exit(a, 0);
		i++;
	}
	if (is_duplicate(a->arr, a->size))
		error_exit(a, 0);
}

int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->arr[i] > a->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	while (!is_sorted(a))
	{
		if (a->arr[0] > a->arr[1])
			sa(a);
		else
			pb(a, b);
	}
	while (b->size > 0)
	{
		pa(a, b);
	}
}
