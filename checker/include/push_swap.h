/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/30 14:16:12 by mahkilic      #+#    #+#                 */
/*   Updated: 2025/01/02 09:22:38 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libft/include/libft.h"
# include "../gnl/get_next_line.h"
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_price;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// ERROR_FREE
void				error_free_stack(t_stack **stack);
void				error_free(t_stack **a);
int					error_syntax(char *str_nbr);
int					error_duplicate(t_stack *a, int nbr);

// STACK & LINKED_LIST FUNCTIONS
void				stack_init(t_stack **a, char **argv);
void				append_node(t_stack **stack, int nbr);
int					stack_len(t_stack *stack);

t_stack				*find_last_node(t_stack *head);
t_stack				*find_smallest(t_stack *stack);
t_stack				*return_cheapest(t_stack *stack);

// SET_NODES FUNCTIONS
void				init_nodes_a(t_stack *a, t_stack *b);
void				init_nodes_b(t_stack *a, t_stack *b);
void				set_current(t_stack *stack);
void				set_price(t_stack *a, t_stack *b);
void				set_cheapest(t_stack *b);

// ALGORITHM & SORING FUNCTIONS
void				push_swap(t_stack **a, t_stack **b);
void				tiny_sort(t_stack **a);
void				rotate_both(t_stack **a, t_stack **b,
						t_stack *cheapest_node);
void				rrotate_both(t_stack **a, t_stack **b,
						t_stack *cheapest_node);
void				prep_for_push(t_stack **stack, t_stack *top_node,
						char stack_name);
void				move_a_to_b(t_stack **a, t_stack **b);
void				move_b_to_a(t_stack **a, t_stack **b);
void				min_on_top(t_stack **a);
void				prep_for_push(t_stack **stack, t_stack *top_node,
						char stack_name);
bool				stack_sorted(t_stack *stack);

t_stack				*find_highest(t_stack *stack);

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