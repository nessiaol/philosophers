#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <time.h>

typedef struct 	s_data
{
	int				number_of_philosophers;
	int				number_of_forks;
	int				number_of_times_each_philosopher_must_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				time_to_eat;
	int				optional_arg;
}					t_data;

// pthread_mutex_t	forchetta;

int			ft_isdigit(int c);
int			ft_atoi(const char *str);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char const *s, int fd);
char		**ft_split(char const *s, char c);
char		*ft_strcat(char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
void		ft_strdel(char **as);
char		*ft_strdup(const char *s1);
void		*ft_memalloc(size_t size);
void		ft_bzero(void *s, size_t n);
size_t		ft_strcpy(char *dst, const char *src);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

void		ft_parse_args(t_data *data, char **argv, int argc);
void		ft_init(t_data *data, int argc);
void		ft_checkargs(int argc, char **argv);
void		ft_create_mutex(t_data *data);
void		ft_create_threads(t_data *data);
void		*PrintHello(t_data *data);

# endif