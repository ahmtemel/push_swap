/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:49:41 by ahmtemel          #+#    #+#             */
/*   Updated: 2022/10/18 22:38:01 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			count++;
		i++;
	}
	if (s[0] == c)
		return (count);
	return (count + 1);
}

static char	**ft_string(char const *s, char c, char **ptr)
{
	int	end;
	int	start;
	int	i;

	start = 0;
	i = 0;
	while (i < ft_counter(s, c))
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end])
			end++;
		ptr[i] = ft_substr(s, start, end - start);
		start = end;
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;

	if (!s || s[0] == 0)
	{
		ptr = ft_calloc(1, sizeof(char *));
		ptr[0] = 0;
		return (ptr);
	}
	ptr = (char **)malloc(sizeof(char *) * (ft_counter(s, c) + 1));
	if (!ptr)
		return (NULL);
	return (ft_string(s, c, ptr));
}
