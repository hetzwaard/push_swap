/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rrotate.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/30 15:52:34 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/01/20 22:45:24 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rrotate(t_stack **stack)
{
	t_stack	*last_node;

	if (*stack == NULL || stack == NULL)
		return ;
	last_node = stack_last_node(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_stack **a, bool checker)
{
	rrotate(a);
	if (!checker)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_stack **b, bool checker)
{
	rrotate(b);
	if (!checker)
		ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack **a, t_stack **b, bool checker)
{
	rrotate(a);
	rrotate(b);
	if (!checker)
		ft_putendl_fd("rrr", 1);
}
