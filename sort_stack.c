/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 22:35:53 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/08/12 10:10:27 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_last_four_two(t_stck *stck)
{
	if (stck->r_b > 0)
	{
		ft_re_rotate_b(stck);
		stck->r_b--;
		ft_printf("rrb\n");
	}
	if (stck->a > 0)
	{
		stck->a--;
		ft_rotate_a(stck);
		ft_printf("ra\n");
	}
}

void	ft_last_four(t_stck *stck)
{
	while (stck->b || stck->r_a || stck->r_b || stck->a)
	{
		if (stck->b > 0)
		{
			ft_rotate_b(stck);
			stck->b--;
			ft_printf("rb\n");
		}
		if (stck->r_a > 0)
		{
			ft_re_rotate_a(stck);
			stck->r_a--;
			ft_printf("rra\n");
		}
		ft_last_four_two(stck);
	}
}

void	ft_final_sort(t_stck *stck)
{
	while ((stck->a && stck->b) || (stck->r_a && stck->r_b))
	{
		if (stck->a && stck->b)
		{
			stck->a--;
			stck->b--;
			ft_rotate_ab(stck);
			ft_printf("rr\n");
		}
		if (stck->r_a && stck->r_b)
		{
			ft_re_rotate_ab(stck);
			stck->r_a--;
			stck->r_b--;
			ft_printf("rrr\n");
		}
	}
	ft_last_four(stck);
	ft_push_to_b(stck);
	ft_printf("pb\n");
}

void	ft_find_best(t_stck *stck)
{
	int	i;
	int	c;

	i = 1;
	c = stck->c_stack[0];
	stck->best = 0;
	while (i < stck->a_count)
	{
		if (stck->c_stack[i] < c)
		{
			c = stck->c_stack[i];
			stck->best = i;
		}
		i++;
	}
}

void	ft_sort_stack(t_stck *stck)
{
	ft_find_best(stck);
	stck->check = 1;
	if (ft_min_max_check(stck, stck->stack[stck->best]))
		stck->c_stack[stck->best] = ft_cal_rot(stck, stck->best);
	else
		stck->c_stack[stck->best] \
			= ft_cal_rot_man(stck, stck->best);
	ft_final_sort(stck);
}
