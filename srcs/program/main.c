
#include "../../includes/philo.h"

void	ft_init(t_data *data, int argc)
{
	data->optional_arg = 0;
	if (argc == 6)
		data->optional_arg = 1;
}

void	ft_create_mutex(t_data *data)
{
	int i;
	pthread_mutex_t *forks;

	i = 0;
	forks = malloc (sizeof (pthread_mutex_t) * data->number_of_forks);
	while (i < data->number_of_forks)
	{
		if(pthread_mutex_init(&forks[i], NULL) == -1)
		{
			printf("***** Couldn't create mutex.\n");
			exit(1);
		}
		i++;
	}
	printf("correctly created %d forks (mutex).\n", i);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_init(&data, argc);
	if (argc == 5 || argc == 6)
	{
		ft_parse_args(&data, argv, argc);
		ft_create_mutex(&data);
		ft_create_threads(&data);

		printf("numero di forchette: %d\n", data.number_of_forks);
		printf("numero di filosofi: %d\n", data.number_of_philosophers);
		printf("ok\n");
	}
	else
	{
		printf("**** Incorrect format. ****\nPlease insert the following arguments to compile: \n\nnumber_of_philosophers \ntime_to_die \ntime_to_eat \
		\ntime_to_sleep \n(optional->) number_of_times_each_philosopher_must_eat\n");
		exit(1);
	}
	return(0);
}