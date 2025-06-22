/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboon <jboon@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/22 12:50:53 by jboon         #+#    #+#                 */
/*   Updated: 2025/06/22 16:01:15 by jboon         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

t_node	*ft_lstnew(char *key, char *value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->key = key;
	node->value = value;
	node->next = NULL;
	return (node);
}
t_node	*ft_lstadd_back(t_node *lst, t_node *node)
{
	t_node	*curr;

	if (lst == NULL)
		return (node);
	curr = lst;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = node;
	return (lst);
}
t_node	*ft_lstfind(t_node *lst, const char *key, int (*cmp)(const char *, const char *))
{
	while (lst)
	{
		if (cmp(lst->key, key) == 0)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
void	ft_lstclear(t_node *lst)
{
	t_node	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst->key);
		free(lst->value);
		free(lst);
		lst = tmp;
	}
}
