/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 21:54:02 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/10/18 21:54:02 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == 0)
	{
		return ((char *)big);
	}
	while (big[i] && i < len)
	{
		while ((big[i + j] == little[j]) && little[j] && (i + j < len))
			j++;
		if (little[j] == '\0')
			return ((char *) big + i);
		i++;
		j = 0;
	}
	return (0);
}
