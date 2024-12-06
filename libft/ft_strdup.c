/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:13:10 by ahmtemel          #+#    #+#             */
/*   Updated: 2022/10/14 23:36:57 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*d;
	size_t	len;

	len = ft_strlen(s1) + 1;
	d = (char *)malloc(len * 1);
	if (!d)
		return (0);
	ft_strlcpy(d, s1, len);
	return (d);
}
