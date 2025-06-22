/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboon <jboon@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/22 17:28:15 by jboon         #+#    #+#                 */
/*   Updated: 2025/06/22 23:43:19 by jboon         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "list.h"
#include "rush02.h"

static int	parse_number_entry(char *line, t_node **dst)
{
	char	*sep;
	char	*key;
	char	*value;

	sep = ft_strchr(line, ':');
	if (sep == NULL)
		return (0);
	*sep = '\0';
	if (!ft_str_isdigit(line))
		return (*sep = ':', 0);
	key = ft_strtrim(line, " \f\n\r\t\v");
	value = ft_strtrim(sep + 1, " \f\n\r\t\v");
	*sep = ':';
	if (key == NULL || value == NULL)
		return (free(key), free(value), -1);
	*dst = ft_lstnew(key, value);
	if (*dst == NULL)
		return (free(key), free(value), -1);
	return (1);
}

static t_node	*parse_dictionary(int fd)
{
	char	buffer[BUF_SIZE];
	char	*line;
	int		status;
	t_node	*lst;
	t_node	*curr;

	lst = NULL;
	buffer[0] = '\0';
	while (1)
	{
		line = NULL;
		if (!ft_get_line(fd, &line, buffer, BUF_SIZE))
			return (ft_lstclear(lst), NULL);
		else if (line == NULL)
			break ;
		status = parse_number_entry(line, &curr);
		if (status == 1)
			lst = ft_lstadd_back(lst, curr);
		else if (status == -1)
			return (free(line), ft_lstclear(lst), NULL);
		free(line);
	}
	return (lst);
}

bool	handle_dictionary(const char *filename, t_node **dict)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_puterr("Failed to open ", filename, "!\n");
		return (false);
	}
	*dict = parse_dictionary(fd);
	if (*dict == NULL)
		ft_puterr("Failed to parse ", filename, "!\n");
	close(fd);
	return (*dict != NULL);
}

bool	validate_input(int argc, char *argv[], const char **filename,
	const char **num_str)
{
	if (argc == 1)
	{
		ft_puterr("Missing arguments: ./", argv[0],
			" <number> [dictionary file]\n");
		return (false);
	}
	else if (argc == 2)
		*filename = "numbers.dict";
	else if (argc == 3)
		*filename = argv[2];
	else
	{
		ft_puterr("Too many arguments: ./", argv[0],
			" <number> [dictionary file]\n");
		return (false);
	}
	if (*argv[1] == '\0' || !ft_str_isdigit(*(argv + 1)))
	{
		ft_puterr("Number argument (", argv[1], ") is not a postive integer\n");
		return (false);
	}
	*num_str = argv[1];
	return (true);
}
