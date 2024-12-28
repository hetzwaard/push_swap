/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/28 15:57:40 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/12/28 16:31:48 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/include/libft.h"

static char	*join_args(int argc, char **argv)
{
	char	*joined_args;
	int		i;
	char	*temp;

	joined_args = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		temp = ft_strjoin(joined_args, argv[i]);
		free(joined_args);
		joined_args = ft_strjoin(temp, " ");
		free(temp);
		i++;
	}
	return (joined_args);
}

char	**parse_input(int argc, char **argv)
{
	char	*joined_args;
	char	**numbers;
	int		i;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	joined_args = join_args(argc, argv);
	numbers = ft_split(joined_args, ' ');
	free(joined_args);
	i = 0;
	while (numbers[i])
	{
		if (!is_numeric(numbers[i]) || check_overflow(numbers[i]))
		{
			ft_free_split(numbers);
			print_error();
		}
		i++;
	}
	if (has_duplicates(numbers))
	{
		ft_free_split(numbers);
		print_error();
	}
	return (numbers);
}
