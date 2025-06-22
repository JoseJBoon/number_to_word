/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   numtoword_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboon <jboon@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/22 23:23:04 by jboon         #+#    #+#                 */
/*   Updated: 2025/06/22 23:33:36 by jboon         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include "rush02.h"

bool	singles(t_node *dict, char *key, const char *num_str)
{
	set_key(key, num_str, 1, 0);
	return (print_value(dict, key));
}

bool	tens(t_node *dict, char *key, const char *num_str)
{
	if (*num_str == '1')
	{
		set_key(key, num_str, 2, 0);
		return (print_value(dict, key));
	}
	set_key(key, num_str, 1, 1);
	if (!print_value(dict, key))
		return (false);
	if (*(num_str + 1) != '0')
	{
		ft_putchar(' ', STDOUT_FILENO);
		return (singles(dict, key, num_str + 1));
	}
	return (true);
}

bool	hundreds(t_node *dict, char *key, const char *num_str)
{
	if (!singles(dict, key, num_str))
		return (false);
	set_key(key, "1", 1, 2);
	ft_putchar(' ', STDOUT_FILENO);
	if (!print_value(dict, key))
		return (false);
	if (*(num_str + 1) != '0')
	{
		ft_putchar(' ', STDOUT_FILENO);
		return (tens(dict, key, num_str + 1));
	}
	else if (*(num_str + 2) != '0')
	{
		ft_putchar(' ', STDOUT_FILENO);
		return (singles(dict, key, num_str + 2));
	}
	return (true);
}

bool	thousands(t_node *dict, char *key, size_t padding)
{
	set_key(key, "1", 1, padding);
	return (print_value(dict, key));
}
