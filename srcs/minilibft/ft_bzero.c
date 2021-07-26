#include "../../includes/philo.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*i;

	i = (unsigned char *)s;
	while (n > 0)
	{
		*i = '\0';
		i++;
		n--;
	}
}
