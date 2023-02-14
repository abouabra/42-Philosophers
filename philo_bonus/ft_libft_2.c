/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:36:04 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/30 16:28:53 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
	{
		s1 = my_alloc(sizeof(char));
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	if (s2 == NULL)
		return (0);
	str = my_alloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	i = -1;
	j = 0;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	return (str);
}
