/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 13:54:31 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/10/16 20:06:54 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst > src)
	{
		i = len;
		while (i > 0)
		{
			i--;
			((unsigned char *) dst)[i] = ((unsigned char *)src)[i];
		}
	}
	else
	{
		ft_memcpy (dst, src, len);
	}
	return (dst);
}
