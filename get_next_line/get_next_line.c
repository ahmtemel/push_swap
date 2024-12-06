/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:20:48 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/09/07 20:19:14 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(char *buffer, int fd)
{
	int		byte;
	char	*str;

	str = malloc(BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	byte = 1;
	while (ft_strchr_get(buffer) && byte != 0)
	{
		byte = read(fd, str, BUFFER_SIZE);
		if (byte == -1)
		{
			free(str);
			return (0);
		}
		str[byte] = '\0';
		buffer = ft_strjoin_get(buffer, str);
	}
	free(str);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = ft_read(buffer, fd);
	if (!buffer)
		return (0);
	line = ft_line(buffer);
	buffer = ft_clean(buffer);
	return (line);
}
