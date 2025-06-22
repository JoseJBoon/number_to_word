/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   getline.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboon <jboon@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/22 16:34:55 by jboon         #+#    #+#                 */
/*   Updated: 2025/06/22 16:37:48 by jboon         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

static char	*construct_line(char *line, char *buffer, size_t cur_len, size_t buf_len)
{
	char	*new_line;

	new_line = malloc((cur_len + buf_len + 1) * sizeof(char));
	if (new_line == NULL)
		return (free(line), NULL);
	if (line != NULL)
		ft_strncpy(new_line, line, cur_len);
	ft_strncpy(new_line + cur_len, buffer, buf_len);
	free(line);
	return (new_line);
}

static bool	append_newline(char **line, char *buffer, size_t *line_len, size_t bytes)
{
	char	*ptr;
	size_t	len;

	ptr = ft_strchrnul(buffer, '\n');
	len = (ptr - buffer) + (*ptr == '\n');
	*line = construct_line(*line, buffer, *line_len, len);
	if (*line == NULL)
		return (false);
	ft_strncpy(buffer, buffer + len, bytes - len);
	*line_len += len;
	return (true);
}

bool	ft_get_line(int fd, char **line, char *buffer, size_t buf_size)
{
	ssize_t	bytes;
	size_t	line_len;

	line_len = 0;
	if (*buffer != '\0')
	{
		if (!append_newline(line, buffer, &line_len, ft_strlen(buffer)))
			return (false);
	}
	while (*line == NULL || *(*line + (line_len - 1)) != '\n')
	{
		bytes = read(fd, buffer, (buf_size - 1));
		if (bytes == -1)
			return (free(line), false);
		buffer[bytes] = '\0';
		if (bytes == 0)
			return (true);
		if (!append_newline(line, buffer, &line_len, bytes))
			return (false);
	}
	return (true);
}
