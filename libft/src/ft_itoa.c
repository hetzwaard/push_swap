/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/23 12:41:15 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/10/23 12:41:15 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	intlen(long nbr)
{
	int	len;

	len = (nbr <= 0);
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

static char	*allocate_memory(int len)
{
	char	*tmp;

	tmp = malloc((len + 1) * 1);
	if (tmp == 0)
		return (0);
	tmp[len] = '\0';
	return (tmp);
}

char	*ft_itoa(int n)
{
	int				i;
	int				len;
	char			*result;
	long			nbr;

	nbr = n;
	len = intlen(nbr);
	result = allocate_memory(len);
	if (result == 0)
		return (0);
	i = len - 1;
	if (nbr == 0)
		result[i] = '0';
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		result[i--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (result);
}
