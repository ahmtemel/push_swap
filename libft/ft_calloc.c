/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:06:27 by ahmtemel          #+#    #+#             */
/*   Updated: 2022/10/14 22:46:45 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	b;

	if (count == 0 && size == 0)
	{
		count = 1;
		size = 1;
	}
	b = count * size;
	ptr = (void *)malloc(b);
	if (!ptr)
		return (0);
	ft_bzero(ptr, b);
	return ((char *)ptr);
}
