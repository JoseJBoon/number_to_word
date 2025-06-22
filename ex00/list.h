/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboon <jboon@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/22 12:44:29 by jboon         #+#    #+#                 */
/*   Updated: 2025/06/22 23:39:43 by jboon         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

typedef struct s_node
{
	char			*key;
	char			*value;
	struct s_node	*next;
}			t_node;

typedef int	(*t_cmp)(const char *, const char *);

t_node	*ft_lstnew(char *key, char *value);
t_node	*ft_lstadd_back(t_node *lst, t_node *node);
t_node	*ft_lstfind(t_node *lst, const char *key, t_cmp cmp);
void	ft_lstclear(t_node *lst);

#endif
