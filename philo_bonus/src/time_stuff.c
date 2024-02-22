/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:56:27 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/30 16:16:14 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	get_interval(time_t before, time_t after)
{
	return (after - before);
}

long	get_time(void)
{
	struct timeval	tmp;
	time_t			elapsed_time;

	gettimeofday(&tmp, NULL);
	elapsed_time = tmp.tv_sec * 1000 + tmp.tv_usec / 1000;
	return (elapsed_time);
}
