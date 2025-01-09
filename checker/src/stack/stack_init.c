/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_init.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/30 14:38:46 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/01/02 00:50:01 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	stack_init(t_stack **a, char **argv)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a);
		if (error_duplicate(*a, (int)nbr))
			error_free(a);
		append_node(a, (int)nbr);
		i++;
	}
}
