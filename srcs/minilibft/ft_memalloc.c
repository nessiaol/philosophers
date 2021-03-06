/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:31:54 by bde-luca          #+#    #+#             */
/*   Updated: 2021/07/26 14:36:13 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*ft_memalloc(size_t size)
{
	char	*ptr;

	ptr = NULL;
	if (size <= 0)
		return (NULL);
	ptr = (char *)malloc(size);
	if (ptr)
	{
		ft_bzero(ptr, size);
	}
	return ((void *)ptr);
}
