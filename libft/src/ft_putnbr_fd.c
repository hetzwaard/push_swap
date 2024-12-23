/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/21 17:45:05 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/10/21 17:45:05 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	size_t	digit;

	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
		ft_putnbr_fd(nb, fd);
		return ;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
	{
		digit = nb + 48;
		write(fd, &digit, 1);
		return ;
	}
}
