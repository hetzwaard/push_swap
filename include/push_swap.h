/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/30 14:16:12 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/01/12 00:47:34 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				*a;
	int				*b;
	int				a_size;
	int				b_size;
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// ERROR_FREE
void				error_free_stack(t_stack **stack);
void				error_free(t_stack **a);
int					error_syntax(char *str_nbr);
int					error_duplicate(t_stack *a, int nbr);

// STACK & LINKED_LIST FUNCTIONS
void				append_node(t_stack **stack, int nbr);
void				stack_init(t_stack **a, char **argv);
int					stack_len(t_stack *stack);
bool				stack_sorted(t_stack *stack);

t_stack				*find_last_node(t_stack *head);
t_stack				*find_highest(t_stack *stack);
t_stack				*find_smallest(t_stack *stack);

// ALGORITHM & SORING FUNCTIONS
void				radix_sort(t_stack **a, t_stack **b);
void				index_stack_values(t_stack *stack);
void				sort_three(t_stack **a);
void				sort_four_to_five(t_stack **a, t_stack **b);

// INSTUCTIONS
void				pa(t_stack **a, t_stack **b, bool checker);
void				pb(t_stack **a, t_stack **b, bool checker);
void				sa(t_stack **a, bool checker);
void				sb(t_stack **b, bool checker);
void				ss(t_stack **a, t_stack **b, bool checker);
void				ra(t_stack **a, bool checker);
void				rb(t_stack **b, bool checker);
void				rr(t_stack **a, t_stack **b, bool checker);
void				rra(t_stack **a, bool checker);
void				rrb(t_stack **b, bool checker);
void				rrr(t_stack **a, t_stack **b, bool checker);

#endif