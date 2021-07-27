#include "../../includes/philo.h"

void	ft_checkargs(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("Argomento (%s) non valido\n", argv[i]);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	ft_parse_args(t_data *data, char **argv, int argc)
{
	ft_checkargs(argc, argv);
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->number_of_forks = data->number_of_philosophers;
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (data->optional_arg)
		data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	printf("numero di forchette: %d\n", data->number_of_forks);
	printf("numero di filosofi: %d\ntime to die: %d\ntime to eat: %d\ntime to sleep: %d\n", data->number_of_philosophers, data->time_to_die, data->time_to_eat, data->time_to_sleep);
	if (data->optional_arg)
		printf("pasti minimi che devono fare i filosofi: %d\n", data->number_of_times_each_philosopher_must_eat);
}