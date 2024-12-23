/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/22 21:25:11 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/10/22 21:25:11 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int			start;
	int			end;
	char		*result;

	start = 0;
	end = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	result = (char *)malloc(1 * (end - start + 2));
	if (result == 0)
		return (0);
	ft_strlcpy(result, &s1[start], end - start + 2);
	result[end - start + 1] = '\0';
	return (result);
}
