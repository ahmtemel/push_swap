/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:51:20 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/08/12 11:15:25 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cal_b(t_stck *stck, int *j, int *r_j, int m)
{
	if ((m + 1) <= (stck->b_count / 2) + 1)
		*j += m;
	else
		*r_j += stck->b_count - m;
}

void	ft_cal_a(t_stck *stck, int *i, int *r_i, int c)
{
	if ((c + 1) <= (stck->a_count / 2) + 1)
		*i += c;
	else
		*r_i += stck->a_count - c;
}

int	ft_find_max(t_stck *stck)
{
	int	j;
	int	i;
	int	c;

	j = 0;
	i = 0;
	c = stck->stack_b[0];
	while (j < stck->b_count)
	{
		if (c < stck->stack_b[j])
		{
			c = stck->stack_b[j];
			i = j;
		}
		j++;
	}
	return (i);
}

int	ft_cal_rot(t_stck *stck, int c)
{
	int	i;
	int	m;
	int	r_i;
	int	j;
	int	r_j;

	m = ft_find_max(stck);
	ft_zero_two(&i, &j, &r_i, &r_j);
	ft_cal_a(stck, &i, &r_i, c);
	ft_cal_b(stck, &j, &r_j, m);
	if (stck->check == 1)
	{
		stck->a = i;
		ft_to_stack(stck, j, r_i, r_j);
	}
	if (i >= j)
		j = 0;
	else
		i = 0;
	if (r_i >= r_j)
		r_j = 0;
	else
		r_i = 0;
	return (i + j + r_i + r_j + 1);
}

int	ft_min_max_check(t_stck *stck, int a)
{
	int	i;
	int	x;
	int	n;

	i = 0;
	x = 0;
	n = 0;
	while (i < stck->b_count)
	{
		if (a >= stck->stack_b[i])
			x++;
		if (a <= stck->stack_b[i])
			n++;
		i++;
	}
	if (x == stck->b_count)
		return (1);
	if (n == stck->b_count)
		return (2);
	return (0);
}
