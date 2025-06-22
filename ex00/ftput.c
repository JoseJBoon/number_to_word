/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ftput.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboon <jboon@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/22 22:20:38 by jboon         #+#    #+#                 */
/*   Updated: 2025/06/22 22:35:57 by jboon         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils.h"

void	ft_putchar(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putstr(const char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	ft_puterr(const char *pre, const char *mid, const char *post)
{
	ft_putstr(pre, STDERR_FILENO);
	if (mid != NULL)
		ft_putstr(mid, STDERR_FILENO);
	if (post != NULL)
		ft_putstr(post, STDERR_FILENO);
}
