/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_func_man.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:11:25 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/08/09 21:36:56 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_to_stack(t_stck *stck, int j, int r_i, int r_j)
{
	stck->b = j;
	stck->r_a = r_i;
	stck->r_b = r_j;
}

void	ft_zero_two(int *i, int *j, int *r_i, int *r_j)
{
	*i = 0;
	*j = 0;
	*r_i = 0;
	*r_j = 0;
}

int	ft_check_where(t_stck *stck, int c)
{
	int		i;
	long	j;
	int		r;

	j = -21474836488;
	i = 0;
	r = 0;
	while (i < stck->b_count)
	{
		if (stck->stack_b[i] < c && j < stck->stack_b[i])
		{
			j = stck->stack_b[i];
			r = i;
		}
		i++;
	}
	return (r);
}

int	ft_cal_rot_man(t_stck *stck, int c)
{
	int	a;
	int	i;
	int	r_i;
	int	j;
	int	r_j;

	a = ft_check_where(stck, stck->stack[c]);
	ft_zero_two(&i, &j, &r_i, &r_j);
	ft_cal_a(stck, &i, &r_i, c);
	ft_cal_b(stck, &j, &r_j, a);
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
