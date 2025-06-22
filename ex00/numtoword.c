/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   numtoword.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboon <jboon@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/22 23:20:36 by jboon         #+#    #+#                 */
/*   Updated: 2025/06/22 23:42:49 by jboon         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include "rush02.h"

static bool	handle_left(t_node *dict, char *key, const char *num_str,
	size_t left)
{
	if (left == 3)
		return (hundreds(dict, key, num_str));
	else if (left == 2)
		return (tens(dict, key, num_str));
	else
		return (singles(dict, key, num_str));
}

static void	assign_groups(size_t len, size_t *left, size_t *right)
{
	if (len < 4)
		*left = len;
	else if (len % 3 == 0)
		*left = len - (3 * ((len / 3) - 1));
	else
		*left = len - (3 * (len / 3));
	*right = len - *left;
}

static const char	*move_num_str(const char *num_str, size_t *len, size_t left)
{
	const char	*last;

	last = num_str + left;
	while (*last == '0')
		++last;
	*len = *len - (last - num_str);
	return (last);
}

bool	number_to_words(t_node *dict, const char *num_str, size_t len)
{
	char	*key;
	size_t	left;
	size_t	right;

	key = malloc((len + 1) * sizeof(char));
	if (key == NULL)
		return (false);
	while (len > 0)
	{
		assign_groups(len, &left, &right);
		if (!handle_left(dict, key, num_str, left))
			return (free(key), false);
		if (right > 0)
		{
			ft_putchar(' ', STDOUT_FILENO);
			if (!thousands(dict, key, right))
				return (free(key), false);
		}
		num_str = move_num_str(num_str, &len, left);
		if (len > 0)
			ft_putchar(' ', STDOUT_FILENO);
	}
	ft_putchar('\n', STDOUT_FILENO);
	return (free(key), true);
}
