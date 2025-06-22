/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_utils_extra.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboon <jboon@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/22 23:29:17 by jboon         #+#    #+#                 */
/*   Updated: 2025/06/22 23:30:43 by jboon         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	const char	*end;

	end = s;
	while (*end)
		++end;
	return (end - s);
}

char	*ft_skipchar(const char *str, char c)
{
	while (*str && *str == c)
		++str;
	return ((char *)str);
}

bool	ft_str_isdigit(const char *s)
{
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (false);
		++s;
	}
	return (true);
}
