/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 02:31:43 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/09/08 06:43:19 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_atoi_max(const char *str, t_stck *stck)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	if (str[i] == '-')
	{
		stck->sign = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (str[i] == '0' && str[i + 1])
		i++;
	while (str[i] >= 48 && str[i] <= 57 && str[i])
	{
		result = ((result * 10) + ((str[i] - 48) * stck->sign));
		if (result > 2147483647 || result < -2147483648
			|| ft_strlen(str + i) > 11)
		{
			write(2, "Error\n", 6);
			exit (1);
		}
		i++;
	}
}
