/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/21 16:46:43 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/10/21 16:46:43 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		i++;
	}
}
