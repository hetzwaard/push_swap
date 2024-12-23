/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/18 20:19:47 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/10/18 20:19:47 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*x;
	const unsigned char	*y;

	x = s1;
	y = s2;
	while (n && *x == *y)
	{
		x++;
		y++;
		--n;
	}
	if (n == 0)
	{
		return (0);
	}
	return (*x - *y);
}
