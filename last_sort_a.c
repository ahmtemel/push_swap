/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_sort_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equinox <equinox@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:48:43 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/08/12 00:36:23 by equinox          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_max_a(t_stck *stck)
{
	int	j;
	int	i;
	int	c;

	j = 0;
	i = 0;
	c = stck->stack[0];
	while (j < stck->a_count)
	{
		if (c < stck->stack[j])
		{
			c = stck->stack[j];
			i = j;
		}
		j++;
	}
	return (i);
}

void	ft_final_final(t_stck *stck)
{
	int	max;

	max = ft_find_max_a(stck);
	while (max != -1 && max != stck->a_count - 1)
	{
		if ((max + 1) >= ((stck->a_count) / 2) - 1)
		{
			ft_re_rotate_a(stck);
			ft_printf("rra\n");
			max++;
		}
		else
		{
			ft_rotate_a(stck);
			ft_printf("ra\n");
			max--;
		}
	}
}

void	ft_rotate_b_last(t_stck *stck, int c)
{
	int	r_i;

	stck->a = 0;
	stck->r_a = 0;
	r_i = 0;
	if ((c + 1) <= (stck->a_count / 2) + 1)
		stck->a = c;
	else
	{
		r_i = stck->a_count - c;
		stck->r_a = r_i;
	}
}

int	ft_check_which(t_stck *stck)
{
	int	i;
	int	r;
	int	c;
	int	check;

	i = 0;
	r = 0;
	check = 0;
	while (i < stck->a_count)
	{
		if (check == 0 && stck->stack_b[0] < stck->stack[i])
		{
			c = stck->stack[i];
			r = i;
			check = 1;
		}
		if (stck->stack_b[0] < stck->stack[i]
			&& stck->stack[i] < c && check == 1)
		{
			c = stck->stack[i];
			r = i;
		}
		i++;
	}
	return (r);
}

void	ft_last_sort_a(t_stck *stck)
{
	int	a;

	a = ft_check_which(stck);
	ft_rotate_b_last(stck, a);
	while (stck->a || stck->r_a)
	{
		if (stck->a)
		{
			ft_rotate_a(stck);
			ft_printf("ra\n");
			stck->a--;
		}
		if (stck->r_a)
		{
			ft_re_rotate_a(stck);
			ft_printf("rra\n");
			stck->r_a--;
		}
	}
}
