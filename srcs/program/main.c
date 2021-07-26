
#include "../../includes/philo.h"

void	ft_parse_args(t_data *data, char **argv, int argc)
{
	ft_checkargs(argc, argv);
	data->number_of_philosophers = ft_atoi(argv[1]);
	if (data->number_of_philosophers == 1)
		data->number_of_forks = 1;
	data->number_of_forks = data->number_of_philosophers;
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (data->optional_arg)
		data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	printf("numero di filosofi: %d\ntime to die: %d\ntime to eat: %d\ntime to sleep: %d\n", data->number_of_philosophers, data->time_to_die, data->time_to_eat, data->time_to_sleep);
	printf("mangiate minime dei filosofi: %d\n", data->number_of_times_each_philosopher_must_eat);
}

void	ft_init(t_data *data, int argc)
{
	data->optional_arg = 0;
	if (argc == 6)
		data->optional_arg = 1;
}

void	cosedainseriredopo()
{
	// pthread_mutex_t	forchetta;
	//pthread_mutex_init(&forchetta, NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;
	// pthread_mutex_t	forchetta;

	ft_init(&data, argc);
	if (argc == 5 || argc == 6)
	{
		ft_parse_args(&data, argv, argc);
		

		//creare una lista di forchette con:
		//pthread_mutex_init(&forchetta, NULL);

		printf("ok\n");
	}
	else
	{
		printf("formato non corretto.\n");
		exit(1);
	}
	return(0);
}