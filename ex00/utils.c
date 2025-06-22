/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboon <jboon@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/22 12:54:16 by jboon         #+#    #+#                 */
/*   Updated: 2025/06/22 21:35:38 by jboon         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

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

size_t	ft_strlen(const char *s)
{
	const char	*end;

	end = s;
	while (*end)
		++end;
	return (end - s);
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

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*words[] = {
// 		"", "a", " ", " a", "a ", "a   a", " a   a ", "a   a ", " a   a", "hello, world!",
// 		" 	 	a	", "\t\thello\t\tworld!\t\t\ttest me"
// 	};

// 	char	*ptr;
// 	// char	*cmp;
// 	int		i;

// 	i = 0;
// 	while (i < 12)
// 	{
// 		// ptr = ft_strchr(words[i], ' ');
// 		// cmp = strchr(words[i], ' ');
// 		// if (ptr != NULL)
// 		// 	printf("%c(%p == %p)\n", *ptr, ptr, cmp);
// 		// else
// 		// 	printf("%p\n", ptr);

// 		// ptr = ft_strchr(words[i], 'a');
// 		// cmp = strchr(words[i], 'a');
// 		// if (ptr != NULL)
// 		// 	printf("%c(%p == %p)\n", *ptr, ptr, cmp);
// 		// else
// 		// 	printf("%p\n", ptr);

// 		ptr = ft_strtrim(words[i], " \t");
// 		if (ptr == NULL)
// 			printf("NULL??\n");
// 		else
// 			printf("%i|%s(%zu)|\n", i, ptr, strlen(ptr));
// 		free(ptr);

// 		printf("\n");
// 		++i;
// 	}

// }
