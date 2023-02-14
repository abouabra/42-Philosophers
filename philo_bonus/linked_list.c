/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:22:07 by abouabra          #+#    #+#             */
/*   Updated: 2023/02/14 17:49:04 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (del != NULL && lst != NULL)
	{
		del(lst->content);
		free(lst);
	}
}

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->content = content;
	node->next = NULL;
	return (node);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *node)
{
	t_list	*tmp;

	if (*lst)
	{
		tmp = ft_lstlast(*lst);
		tmp->next = node;
	}
	else
		*lst = node;
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (del != NULL && lst != NULL)
	{
		while (*lst != NULL)
		{
			tmp = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = tmp;
		}
		*lst = NULL;
	}
}
