/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 21:05:47 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/10/18 14:53:56 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlen(const char *s)

{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}
