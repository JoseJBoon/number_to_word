/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboon <jboon@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/22 12:50:39 by jboon         #+#    #+#                 */
/*   Updated: 2025/06/22 12:50:39 by jboon         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"
#include "utils.h"

#include <stdio.h>

void	print_value(t_node *dict, const char *key)
{
	t_node	*node;

	node = ft_lstfind(dict, key, ft_strcmp);
	if (node == NULL)
		return ;
	ft_putstr(node->value, STDOUT_FILENO);
}

void	set_key(char *key, const char *num_str, int digits, int padding)
{
	int	i;

	i = 0;
	while (i < digits)
	{
		key[i] = num_str[i];
		++i;
	}
	padding += i;
	while (i < padding)
	{
		key[i] = '0';
		++i;
	}
	key[i] = '\0';
}

static void	singles(t_node *dict, char *key, const char *num_str)
{
	set_key(key, num_str, 1, 0);
	print_value(dict, key);
}

static void tens(t_node *dict, char *key, const char *num_str)
{
	if (*num_str == '1')
	{
		set_key(key, num_str, 2, 0);
		print_value(dict, key);
	}
	else
	{
		set_key(key, num_str, 1, 1);
		print_value(dict, key);
		if (*(num_str + 1) != '0')
		{
			ft_putchar(' ', STDOUT_FILENO);
			singles(dict, key, num_str + 1);
		}
	}
}

static void	hundreds(t_node *dict, char *key, const char *num_str)
{
	singles(dict, key, num_str);
	set_key(key, "1", 1, 2);
	ft_putchar(' ', STDOUT_FILENO);
	print_value(dict, key);
	if (*(num_str + 1) != '0')
	{
		ft_putchar(' ', STDOUT_FILENO);
		tens(dict, key, num_str + 1);
	}
	else if (*(num_str + 2) != '0')
	{
		ft_putchar(' ', STDOUT_FILENO);
		singles(dict, key, num_str + 2);
	}
}

static void	thousands(t_node *dict, char *key, size_t padding)
{
	set_key(key, "1", 1, padding);
	print_value(dict, key);
}

static void	handle_left(t_node *dict, char *key, const char *num_str, size_t digits)
{
	if (digits == 3)
		hundreds(dict, key, num_str);
	else if (digits == 2)
		tens(dict, key, num_str);
	else
		singles(dict, key, num_str);
}

char	*ft_skipchar(const char *str, char c)
{
	while (*str && *str == c)
		++str;
	return ((char *)str);
}

bool	number_to_words(t_node *dict, const char *num_str)
{
	char	*key;
	size_t	len;
	size_t	left;
	size_t	right;

	while (*num_str && *num_str == '0' && *(num_str + 1) == '0')
		++num_str;
	len = ft_strlen(num_str);
	key = malloc((len + 1) * sizeof(char));
	if (key == NULL)
		return (false); // failure...
	while (len > 0)
	{
		if (len < 4)
			left = len;
		else if (len % 3 == 0)
			left = len - (3 * ((len / 3) - 1));
		else
			left = len - (3 * (len / 3));
		right = len - left;
		handle_left(dict, key, num_str, left);
		if (right > 0)
		{
			ft_putchar(' ', STDOUT_FILENO);
			thousands(dict, key, right);
		}
		len -= left;
		num_str = num_str + left;
		while (*num_str == '0')
		{
			--len;
			++num_str;
		}
		if (len > 0)
			ft_putchar(' ', STDOUT_FILENO);
	}
	ft_putchar('\n', STDOUT_FILENO);
	free(key);
	return (true);
}

void	tester_function(t_node *dict)
{
	const char	*number[] = {
		"0", "2", "13", "25", "66", "100", "101", "505", "999", "1000",
		"5001", "40001", "900001", "1000000", "1000000000000000000000000000000000000",
		"1000000000000000000000000000000000001", "100000000000000000000000000000000000000",
		"105000000000000005500000000000000000050", "00001", "589871356",
		"113111111111111112111111111111111111111", "5555", "1111", "1025486"
	};
	size_t		i;

	i = 0;
	while (i < (sizeof(number) / sizeof(char *)))
	{
		ft_putstr(number[i], STDOUT_FILENO);
		ft_putchar('\n', STDOUT_FILENO);
		number_to_words(dict, number[i]);
		ft_putchar('\n', STDOUT_FILENO);
		++i;
	}
}

int	main(int argc, char *argv[])
{
	const char	*filename;
	const char	*num_str;
	t_node		*dict;

	if (!validate_input(argc, argv, &filename, &num_str)
		|| !handle_dictionary(filename, &dict))
		return (1);
	if (!number_to_words(dict, num_str))
	{
		ft_puterr("Failed to convert ", num_str, "!\n");
		ft_lstclear(dict);
		return (1);
	}
	ft_lstclear(dict);
	return (0);
}
