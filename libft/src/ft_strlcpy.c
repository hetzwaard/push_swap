/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/14 12:52:30 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/10/14 13:03:02 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, unsigned int size)

{
	unsigned int	i;
	unsigned int	x;

	x = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (src [i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (x);
}
