/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:19:42 by abouabra          #+#    #+#             */
/*   Updated: 2023/02/14 17:49:42 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	garbage_collector(void *adress, int arg)
{
	static t_list	*head;
	t_list			*node;

	if (arg)
		ft_lstclear(&head, free);
	else
	{
		node = ft_lstnew(adress);
		ft_lstadd_back(&head, node);
	}
}

void	custom_exit(int exit_code)
{
	garbage_collector(NULL, 1);
	exit(exit_code);
}

void	*my_alloc(size_t size)
{
	void	*str;

	str = malloc(size);
	if (!str)
		return (0);
	memset(str, 0, size);
	garbage_collector(str, 0);
	return (str);
}
