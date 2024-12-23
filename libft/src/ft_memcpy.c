/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/11 13:36:20 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/10/16 14:43:26 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*char_dest;
	char	*char_src;

	char_dest = (char *) dest;
	char_src = (char *) src;
	if (!dest && !src && n > 0)
		return (0);
	while (n--)
	{
		*char_dest++ = *char_src++;
	}
	return (dest);
}
