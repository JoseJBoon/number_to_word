/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboon <jboon@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/22 12:58:37 by jboon         #+#    #+#                 */
/*   Updated: 2025/06/22 22:36:19 by jboon         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdbool.h>
# include "list.h"

# ifndef BUF_SIZE
# define BUF_SIZE 1024
# endif

char	*ft_strchr(const char *s, int c);
char	*ft_strchrnul(const char *s, int c);
char	*ft_strncpy(char *dst, const char *src, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strtrim(const char *str, const char *set);
bool	ft_str_isdigit(const char *s);

bool	ft_get_line(int fd, char **line, char *buffer, size_t buf_size);

bool	validate_input(int argc, char *argv[], const char **filename, const char **num_str);
bool	handle_dictionary(const char *filename, t_node **dict);

void	ft_putchar(char c, int fd);
void	ft_putstr(const char *s, int fd);
void	ft_puterr(const char *pre, const char *mid, const char *post);

#endif
