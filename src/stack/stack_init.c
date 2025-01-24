/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_init.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/30 14:38:46 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/01/20 22:52:36 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	check_syntax(char *str_nbr)
{
	if (!(*str_nbr == '+' || *str_nbr == '-' || (*str_nbr >= '0'
				&& *str_nbr <= '9')))
		return (1);
	if ((*str_nbr == '+' || *str_nbr == '-') && !(str_nbr[1] >= '0'
			&& str_nbr[1] <= '9'))
		return (1);
	while (*++str_nbr)
	{
		if (!(*str_nbr >= '0' && *str_nbr <= '9'))
			return (1);
	}
	return (0);
}

static int	check_duplicate(t_stack *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

static void	append_node(t_stack **stack, int nbr)
{
	t_stack	*node;
	t_stack	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = stack_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

static int	stack_check(t_stack **a, char **argv)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (check_syntax(argv[i]))
			return (1);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (1);
		if (check_duplicate(*a, (int)nbr))
			return (1);
		append_node(a, (int)nbr);
		i++;
	}
	return (0);
}

int	stack_init(int argc, char **argv, t_stack **a)
{
	char	**arr;
	int		ret;

	arr = NULL;
	ret = 0;
	if (argc == 1)
		return (1);
	else if ((argc == 2 && !argv[1][0]))
		stack_error(a, argv);
	else if (argc == 2 && argv[1][0])
	{
		arr = ft_split_ps(argv[1], ' ');
		ret = stack_check(a, arr + 1);
		ft_free_arr(arr);
	}
	else
		ret = stack_check(a, argv + 1);
	if (ret == 1)
		stack_error(a, argv);
	return (0);
}
