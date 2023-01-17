/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:36:04 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/17 13:07:53 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*str;

	str = malloc(nitems * size);
	if (!str)
		return (0);
	memset(str, 0, nitems * size);
	return (str);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	final;

	i = 0;
	sign = 1;
	final = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		final = final * 10 + str[i] - '0';
		i++;
	}
	return (final * sign);
}

static int	int_len(long n)
{
	int	counter;

	counter = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		counter++;
	}
	while (n > 0)
	{
		counter++;
		n = n / 10;
	}
	return (counter);
}

static char	*format(long nb, int len, char *str)
{
	if (nb < 0)
	{
		nb = nb * -1;
		str[0] = '-';
	}
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (nb > 0)
	{
		str[len] = nb % 10 + 48;
		nb = nb / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	nb;

	nb = n;
	len = int_len(n);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	len--;
	str = format(nb, len, str);
	return (str);
}

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
		s1 = malloc(1 * sizeof(char));
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	if (s2 == NULL)
		return (0);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	i = -1;
	j = 0;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	free(s1);
	return (str);
}
