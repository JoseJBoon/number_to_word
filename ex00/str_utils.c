/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_utils.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboon <jboon@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/22 12:54:16 by jboon         #+#    #+#                 */
/*   Updated: 2025/06/22 23:30:48 by jboon         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != c)
		++s;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strchrnul(const char *s, int c)
{
	while (*s && *s != c)
		++s;
	return ((char *)s);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strtrim(const char *str, const char *set)
{
	char	*dst;
	char	*end;
	size_t	len;
	size_t	i;

	while (*str && ft_strchr(set, *str))
		++str;
	end = ft_strchr(str, '\0');
	while (str != end && ft_strchr(set, *(end - 1)))
		--end;
	len = end - str;
	dst = malloc((len + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = str[i];
		++i;
	}
	dst[i] = '\0';
	return (dst);
}
