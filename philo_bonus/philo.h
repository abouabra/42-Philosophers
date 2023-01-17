/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:57:15 by abouabra          #+#    #+#             */
/*   Updated: 2023/01/17 14:35:25 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct t_args
{
	int				n_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_times_must_eat;

	time_t			initial_time;
	int				id;
	
	int				kill_yourself;
	long			eating_times;
	long			eating_duration;

	sem_t *forks;
}					t_args;

enum
{
	IS_TAKING_FORK,
	IS_EATING,
	IS_SLEEPING,
	IS_THINKING,
	IS_DEAD,
	IS_FULL,
};


void				*ft_calloc(size_t nitems, size_t size);
int					ft_atoi(const char *str);
int					check_args(t_args *vars, char **av);
void				end_phase(t_args *vars);
void				make_philos(t_args *vars);
void				*handle_philo(void *arg);
long				get_interval(time_t before, time_t after);
long				get_time(void);
void				ft_usleep(t_args *vars, int time);
int	is_full(t_args *vars);
void				print_status(t_args *vars, int status, int id);

char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_itoa(int n);
int	is_every_one_ate(t_args *vars);

#endif