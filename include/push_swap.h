/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/28 15:58:59 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/12/29 00:11:55 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*values;
	int	size;
}		t_stack;

// INSTRUCTIONS
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// SORTING
int		find_smallest(t_stack *stack);
void	push_smallest_to_b(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);

// INPUT
char	**parse_input(int argc, char **argv);

// VALIDATION
int		is_numeric(const char *str);
int		check_overflow(const char *str);
int		has_duplicates(char **numbers);

// UTILS
void	print_error(void);
void	free_split(char **split);
t_stack	*init_stack(int size);

#endif
