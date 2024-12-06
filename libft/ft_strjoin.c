/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 08:25:16 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/08/08 04:50:18 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		s1len;
	int		s2len;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (0);
	s1len = (int)ft_strlen(s1);
	s2len = (int)ft_strlen(s2);
	str = (char *)malloc(s1len + s2len + 1);
	if (!str)
		return (0);
	while (i < s1len)
	{
		*(str + i) = *(char *)(s1 + i);
		i++;
	}
	while (j < s2len)
		*(str + i++) = *(char *)(s2 + j++);
	*(str + i) = 0;
	return (str);
}
