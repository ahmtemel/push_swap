/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:34:22 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/09/08 06:37:22 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_int_min(t_stck *stck)
{
	int	i;

	i = 0;
	while (stck->stc[i])
	{
		ft_atoi_max(stck->stc[i], stck);
		i++;
	}
}

void	ft_check_same(t_stck *stck)
{
	int	i;
	int	j;

	i = 0;
	if (stck->ac > 1)
	{
		while (i < stck->ac)
		{
			j = 0;
			while ((j + 1) < stck->ac)
			{
				if (stck->stack[i] == stck->stack[j + 1] && (j + 1) != i)
				{
					write(2, "Error\n", 6);
					exit (1);
				}
				j++;
			}
			i++;
		}
	}
}

void	ft_convert_string(t_stck *stck)
{
	int	i;

	i = 0;
	while (stck->stc[i])
	{
		stck->stack[i] = ft_atoi(stck->stc[i]);
		i++;
	}
}

void	ft_check_int(t_stck *stck)
{
	int	i;
	int	j;

	i = 0;
	while (stck->stc[i])
	{
		j = 0;
		while (stck->stc[i][j])
		{
			if ((stck->stc[i][j] == '-' || stck->stc[i][j] == '+')
				&& j == 0)
				j++;
			if ((stck->stc[i][j] > 57 || stck->stc[i][j] < 48))
			{
				write(2, "Error\n", 6);
				free_arr(stck->stc);
				exit (1);
			}
			j++;
		}
		i++;
	}
	stck->a_count = i;
	stck->ac = i;
}
