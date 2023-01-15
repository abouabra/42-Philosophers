/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:57:15 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/14 17:50:17 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct t_args {
	int n_of_philos;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int n_times_must_eat;
	
	pthread_t th[200];
	pthread_mutex_t mutex[200];
	time_t initial_time;

	int eating_times[200];
	long eating_duration[200];
	int kill_yourself;
	int *index;
} t_args;

void    *ft_calloc(size_t nitems, size_t size);
int     ft_atoi(const char *str);
int check_args(t_args *vars, char **av);
void end_phase(t_args *vars);
void make_philos(t_args *vars);
void *handle_philo(void *arg);

long get_interval(time_t before, time_t after);
long get_time(void);
void ft_usleep(int ms);
int	is_every_one_ate(t_args *vars);

void print_status(t_args *vars, char *status, int id);


#endif