/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rush02.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboon <jboon@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/22 12:58:37 by jboon         #+#    #+#                 */
/*   Updated: 2025/06/22 23:40:54 by jboon         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <stdbool.h>
# include <stddef.h>
# include "list.h"

# ifndef BUF_SIZE
#  define BUF_SIZE 1024
# endif

/* str_utils.c */

char	*ft_strchr(const char *s, int c);
char	*ft_strchrnul(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strncpy(char *dst, const char *src, size_t n);
char	*ft_strtrim(const char *str, const char *set);

/* str_utils_extra.c */

size_t	ft_strlen(const char *s);
char	*ft_skipchar(const char *str, char c);
bool	ft_str_isdigit(const char *s);

/* getline.c */

bool	ft_get_line(int fd, char **line, char *buffer, size_t buf_size);

/* parse.c */

bool	validate_input(int argc, char *argv[], const char **filename,
			const char **num_str);
bool	handle_dictionary(const char *filename, t_node **dict);

/* ftput.c */

void	ft_putchar(char c, int fd);
void	ft_putstr(const char *s, int fd);
void	ft_puterr(const char *pre, const char *mid, const char *post);

/* dict_utils.c */

void	set_key(char *key, const char *num_str, int digits, int padding);
bool	print_value(t_node *dict, const char *key);

/* numtoworld.c */

bool	number_to_words(t_node *dict, const char *num_str, size_t len);

/* numtoworld_utils.c */

bool	singles(t_node *dict, char *key, const char *num_str);
bool	tens(t_node *dict, char *key, const char *num_str);
bool	hundreds(t_node *dict, char *key, const char *num_str);
bool	thousands(t_node *dict, char *key, size_t padding);

#endif
