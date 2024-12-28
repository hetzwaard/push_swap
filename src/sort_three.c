/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_three.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/28 21:46:38 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/12/28 23:52:13 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack *a)
{
	if (a->values[0] > a->values[1] && a->values[1] < a->values[2]
		&& a->values[0] < a->values[2])
		sa(a);
	else if (a->values[0] > a->values[1] && a->values[1] > a->values[2])
	{
		sa(a);
		rra(a);
	}
	else if (a->values[0] > a->values[1] && a->values[1] < a->values[2]
		&& a->values[0] > a->values[2])
		ra(a);
	else if (a->values[0] < a->values[1] && a->values[1] > a->values[2]
		&& a->values[0] < a->values[2])
	{
		sa(a);
		ra(a);
	}
	else if (a->values[0] < a->values[1] && a->values[1] > a->values[2]
		&& a->values[0] > a->values[2])
		rra(a);
}
