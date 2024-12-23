/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/21 13:59:16 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/10/21 13:59:16 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tmp;

	tmp = malloc(nmemb * size);
	if (tmp == 0)
		return (0);
	ft_bzero ((char *)tmp, nmemb * size);
	return (tmp);
}
