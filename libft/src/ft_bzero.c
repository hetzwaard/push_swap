/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 13:35:15 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/10/16 13:04:22 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*clean;

	clean = s;
	while (n != 0)
	{
		*clean++ = 0;
		n--;
	}
}
