/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mahkilic <mahkilic@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/18 15:48:58 by mahkilic      #+#    #+#                 */
/*   Updated: 2024/11/28 17:15:03 by mahkilic      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*left_over(char *storage, int *ret)
{
	char	*new_storage;
	char	*ptr;
	int		len;

	ptr = ft_gnl_strchr(storage, '\n');
	if (!ptr)
		return (*ret = 1, free(storage), storage = NULL,
			new_storage = NULL, NULL);
	else
		len = (ptr - storage) + 1;
	if (!storage[len])
		return (*ret = 1, free(storage), storage = NULL, NULL);
	new_storage = ft_gnl_substr(storage, len, ft_gnl_strlen(storage) - len);
	(free(storage), storage = NULL);
	if (!new_storage)
		*ret = 2;
	else
		*ret = 1;
	return (new_storage);
}

static char	*new_line(char *storage)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_gnl_strchr(storage, '\n');
	len = (ptr - storage) + 1;
	line = ft_gnl_substr(storage, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

static char	*read_buffer(int fd, char *storage)
{
	int		bytes_read;
	char	*buffer;

	bytes_read = 1;
	buffer = malloc((BUFFER_SIZE + 1) * 1);
	if (!buffer)
		return (free(storage), storage = NULL, NULL);
	buffer[0] = '\0';
	while (bytes_read > 0 && !ft_gnl_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			storage = ft_gnl_strjoin(storage, buffer);
			if (!storage)
				return (free(buffer), buffer = NULL, NULL);
		}
	}
	free(buffer);
	if (bytes_read == -1)
		return (free(storage), storage = NULL, NULL);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(storage), storage = NULL, NULL);
	if (!storage || !ft_gnl_strchr(storage, '\n'))
		storage = read_buffer(fd, storage);
	if (!storage)
		return (NULL);
	line = new_line(storage);
	if (!line)
		return (free(storage), storage = NULL, NULL);
	ret = 0;
	storage = left_over(storage, &ret);
	if (ret == 2)
		return (free(line), line = NULL, NULL);
	return (line);
}
