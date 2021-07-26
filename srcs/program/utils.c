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