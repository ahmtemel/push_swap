/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 03:10:55 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/09/08 06:37:38 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_min(int c, t_stck *stck)
{
	int	i;
	int	r;

	i = 0;
	r = 1;
	while (i < stck->a_count)
	{
		if (stck->stack[i] > c)
		{
			r = 0;
			break ;
		}
		i++;
	}
	if (r == 1)
	{
		i = ft_find_min_a(stck);
		if ((i + 1) <= (stck->a_count / 2) + 1)
			stck->a = i;
		else
			stck->r_a = stck->a_count - i;
	}
	return (r);
}

void	ft_check_space(char **stc, int ac, t_stck *stck)
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
			free_arr(stck->stc);
			exit (1);
		}
		i++;
	}
}

void	ft_check_null(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
			j++;
		if (j == 0)
		{
			write(2, "Error\n", 6);
			exit (1);
		}
		i++;
	}
}

int	ft_check_sort_tree(t_stck *stck)
{
	int	i;
	int	j;
	int	check;
	int	sort;

	i = 0;
	sort = 0;
	while (i < stck->a_count)
	{
		check = stck->stack[i];
		j = i + 1;
		while (j < stck->a_count)
		{
			if (stck->stack[j] < check && sort == 0)
				sort = -1;
			j++;
		}
		i++;
	}
	if (sort == 0)
		return (0);
	return (1);
}

int	ft_find_a(t_stck *stck)
{
	if (stck->stack[1] > stck->stack[0] && \
			stck->stack[1] < stck->stack[2])
		return (1);
	return (0);
}
