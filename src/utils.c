/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/28 16:08:28 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/12/28 21:50:26 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/include/libft.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

t_stack	*init_stack(int size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->values = (int *)malloc(sizeof(int) * size);
	if (!stack->values)
	{
		free(stack);
		return (NULL);
	}
	stack->size = 0;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	if (!stack)
		return ;
	free(stack->values);
	free(stack);
}
