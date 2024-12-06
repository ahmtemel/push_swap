/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_max_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:03:59 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/09/08 07:51:04 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_re_rotate_ab_bonus(t_stack *stck)
{
	ft_re_rotate_a_bonus(stck);
	ft_re_rotate_b_bonus(stck);
}

void	ft_atoi_max_bonus(const char *str, t_stack *stck)
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

void	ft_free_bonus(t_stack *stck)
{
	free(stck->stack);
	free(stck->stack_b);
	free(stck->c_stack);
}

void	free_arr_bonus(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
}
