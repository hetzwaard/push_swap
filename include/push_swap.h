/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/21 15:27:35 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/12/21 15:27:35 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

// STACK STRUCTURE
typedef struct s_stack
{
	int	*arr;
	int	size;
}	t_stack;

// UTILITY FUNCTIONS
void	error_exit(t_stack *a, t_stack *b);
void	free_stacks(t_stack *a, t_stack *b);
void	validate_and_fill_stack(t_stack *stack, int argc, char **argv);
int		is_sorted(t_stack *stack);
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);

// OPERATIONS
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

// SORTING FUNCTION
void	sort_stack(t_stack *a, t_stack *b);

#endif
