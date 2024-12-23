/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/23 15:49:49 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/10/23 15:49:49 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_safe_malloc(char **token_v, int position, size_t buffer)
{
	int	i;

	i = 0;
	token_v[position] = malloc(buffer);
	if (token_v[position] == 0)
	{
		while (i < position)
		{
			free(token_v[i++]);
		}
		free(token_v);
		return (1);
	}
	return (0);
}

static int	ft_fill(char **token_v, char const *s, char delimeter)
{
	size_t		len;
	int			i;
	const char	*start;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == delimeter && *s)
			s++;
		start = s;
		while (*s != delimeter && *s)
		{
			++len;
			++s;
		}
		if (len)
		{
			if (ft_safe_malloc(token_v, i, len + 1))
				return (1);
			ft_strlcpy(token_v[i], start, len + 1);
			i++;
		}
	}
	return (0);
}

static size_t	ft_count_tokens(char const *s, char delimeter)
{
	size_t	tokens;

	tokens = 0;
	while (*s)
	{
		while (*s == delimeter && *s)
			s++;
		if (*s && *s != delimeter)
		{
			tokens++;
			while (*s != delimeter && *s)
				s++;
		}
	}
	return (tokens);
}

char	**ft_split(char const *s, char c)
{
	size_t	tokens;
	char	**token_v;

	if (s == 0)
		return (0);
	tokens = ft_count_tokens(s, c);
	token_v = (char **)malloc((tokens + 1) * sizeof(char *));
	if (token_v == 0)
		return (0);
	token_v[tokens] = 0;
	if (ft_fill(token_v, s, c))
	{
		return (0);
	}
	return (token_v);
}
