/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_checks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/26 18:32:10 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/12/26 18:32:26 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/include/libft.h"

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_duplicates(t_stack *stack)
{
	int i;
	int j;

	i = 0;
	while (i < stack->size)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->arr[i] == stack->arr[j])
				error_exit(stack, NULL);
			j++;
		}
		i++;
	}
}
