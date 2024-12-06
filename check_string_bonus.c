/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_string_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:57:13 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/09/08 06:35:49 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_check_space_bonus(char **stc, int ac, t_stack *stck)
{
	int	i;
	int	j;
	int	c;

	i = 1;
	j = 0;
	c = 0;
	while (i < ac)
	{
		j = 0;
		c = 0;
		while (stc[i][j])
		{
			if (stc[i][j] == ' ')
				c++;
			j++;
		}
		if (j == c)
		{
			write(2, "Error\n", 6);
			free_arr_bonus(stck->stc);
			exit (1);
		}
		i++;
	}
}

void	ft_check_int_min_bonus(t_stack *stck)
{
	int	i;

	i = 0;
	while (stck->stc[i])
	{
		ft_atoi_max_bonus(stck->stc[i], stck);
		i++;
	}
}

void	ft_check_int_bonus(t_stack *stck)
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
				free_arr_bonus(stck->stc);
				exit (1);
			}
			j++;
		}
		i++;
	}
	stck->a_count = i;
	stck->ac = i;
}

void	ft_convert_string_bonus(t_stack *stck)
{
	int	i;

	i = 0;
	while (stck->stc[i])
	{
		stck->stack[i] = ft_atoi(stck->stc[i]);
		i++;
	}
}

void	ft_check_same_bonus(t_stack *stck)
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
