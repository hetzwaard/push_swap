/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/28 15:58:59 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/12/28 16:07:47 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

// INPUT
char	**parse_input(int argc, char **argv);

// VALIDATION
int		is_numeric(const char *str);
int		check_overflow(const char *str);
int		has_duplicates(char **numbers);

// UTILS
void	print_error(void);
void	ft_free_split(char **split);

#endif
