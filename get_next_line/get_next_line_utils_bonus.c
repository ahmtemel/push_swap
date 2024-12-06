/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:01:36 by ahmtemel          #+#    #+#             */
/*   Updated: 2022/12/04 11:03:18 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return (1);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_line(char *buffer)
{
	int		i;
	char	*str;

	i = 0;
	if (!buffer[i])
		return (0);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		str[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_clean(char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (0);
	}
	str = malloc(ft_strlen(buffer) - i + 1);
	i++;
	while (buffer[i])
		str[j++] = buffer[i++];
	str[j] = '\0';
	free(buffer);
	return (str);
}

char	*ft_strjoin(char *buffer, char *str)
{
	int		i;
	char	*s;
	int		j;

	if (!buffer)
	{
		buffer = malloc(1);
		buffer[0] = '\0';
	}
	if (!str)
		return (0);
	i = -1;
	j = 0;
	s = malloc(ft_strlen(buffer) + ft_strlen(str) + 1);
	if (!s)
		return (0);
	while (buffer[++i] != '\0')
		*(s + i) = *(buffer + i);
	while (str[j] != '\0')
		*(s + i++) = *(str + j++);
	*(s + i) = '\0';
	free(buffer);
	return (s);
}
