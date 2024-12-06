/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 11:02:04 by ahmtemel          #+#    #+#             */
/*   Updated: 2022/12/04 11:20:12 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line_bonus(int fd);
char	*ft_strjoin(char *buffer, char *str);
char	*ft_line(char *buffer);
char	*ft_clean(char *buffer);
int		ft_strlen(char *str);
int		ft_strchr(char *buffer);

#endif
