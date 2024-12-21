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

void	error_exit(t_stack *a, t_stack *b)
{
	write(2, "Error\n", 6);
	free_stacks(a, b);
	exit(EXIT_FAILURE);
}

void	print_operation(char *op)
{
	write(1, op, ft_strlen(op));
	write(1, "\n", 1);
}

size_t	ft_strlen(const char *s)

{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t'
		|| nptr[i] == '\n' || nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr [i] == '\r')
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
