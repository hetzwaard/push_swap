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

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				*arr;
	int				size;
	struct s_stack *next;
}		t_stack;

// UTILS

size_t	ft_strlen(const char *s);
void	print_operation(char *op);
void	error_exit(t_stack *a, t_stack *b);
int		ft_atoi(const char *nptr);

// OPERATIONS

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

void	rra(t_stack *a);
void	rrb(t_stack *b);

void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

// ARGS

int		is_valid(char *str);
int		is_duplicate(int *arr, int size);
int		is_sorted(t_stack *a);

void	sort_stack(t_stack *a, t_stack *b);
void	validate_and_fill_stack(t_stack *a, int argc, char **argv);

// OTHER

void	free_stacks(t_stack *a, t_stack *b);

#endif