/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/21 15:11:22 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/10/21 15:11:22 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s)
{
	char	*ns;
	size_t	len;

	len = ft_strlen(s);
	ns = (char *)malloc(len + 1);
	if (ns == 0)
		return (0);
	ft_strlcpy(ns, s, len + 1);
	return (ns);
}
