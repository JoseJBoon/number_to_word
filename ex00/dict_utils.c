/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dict_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboon <jboon@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/22 23:24:16 by jboon         #+#    #+#                 */
/*   Updated: 2025/06/22 23:33:36 by jboon         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>
#include "rush02.h"

bool	print_value(t_node *dict, const char *key)
{
	t_node	*node;

	node = ft_lstfind(dict, key, ft_strcmp);
	if (node == NULL)
		return (false);
	ft_putstr(node->value, STDOUT_FILENO);
	return (true);
}

void	set_key(char *key, const char *num_str, int digits, int padding)
{
	int	i;

	i = 0;
	ft_strncpy(key, num_str, digits);
	while (i < padding)
	{
		key[digits + i] = '0';
		++i;
	}
	key[digits + i] = '\0';
}
