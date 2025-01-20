/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/01/02 01:18:37 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/01/14 21:50:24 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	stack_free(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->value = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

int	stack_len(t_stack *stack)
{
	int	count;

	if (stack == NULL)
		return (0);
	count = 0;
	while (stack)
	{
		++count;
		stack = stack->next;
	}
	return (count);
}

bool	stack_sorted(t_stack *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack	*find_last_node(t_stack *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

int	parser(int argc, char **argv, t_stack **a)
{
	char	**arr;
	int		ret;

	arr = NULL;
	ret = 0;
	if (argc == 1)
		return (1);
	else if ((argc == 2 && !argv[1][0]) || (argc == 2 && (argv[1][0]) == ' '))
		error_free(a, argv);
	else if (argc == 2 && argv[1][0])
	{
		arr = ft_split_ps(argv[1], ' ');
		ret = stack_init(a, arr + 1);
		ft_free_arr(arr);
	}
	else
		ret = stack_init(a, argv + 1);
	if (ret == 1)
		error_free(a, argv);
	return (0);
}
