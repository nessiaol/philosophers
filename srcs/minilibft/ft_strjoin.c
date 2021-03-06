/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:28:31 by dmangola          #+#    #+#             */
/*   Updated: 2021/07/26 14:36:48 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;

	ptr = NULL;
	ptr = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s1 && s2 && ptr)
	{
		ft_strcpy(ptr, s1);
		if (ft_strlen(s1) == 0)
			i = 0;
		else
			i = ft_strlen(s1) - 1;
		ft_strcat(&ptr[i], s2);
	}
	return (ptr);
}
