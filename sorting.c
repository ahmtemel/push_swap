/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 13:51:58 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/09/08 07:58:59 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three_two(t_stck *stck)
{
	if (stck->stack[0] < stck->stack[2])
	{
		ft_swap_a(stck);
		ft_printf("sa\n");
	}
	else if (stck->stack[1] < stck->stack[2])
	{
		ft_rotate_a(stck);
		ft_printf("ra\n");
	}
	else
	{
		ft_rotate_a(stck);
		ft_swap_a(stck);
		ft_printf("ra\n");
		ft_printf("sa\n");
	}
}

void	ft_calculate(t_stck *stck)
{
	int	i;

	i = 0;
	free(stck->c_stack);
	stck->c_stack = (int *)malloc(sizeof(int) * stck->a_count);
	while (i < stck->a_count)
	{
		if (ft_min_max_check(stck, stck->stack[i]))
			stck->c_stack[i] = ft_cal_rot(stck, i);
		else
			stck->c_stack[i] = ft_cal_rot_man(stck, i);
		i++;
	}
}

void	ft_check_sort(t_stck *stck)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	while (i < stck->a_count)
	{
		check = stck->stack[i];
		j = i + 1;
		while (j < stck->a_count)
		{
			if (stck->stack[j] < check && stck->sort == 0)
				stck->sort = -1;
			j++;
		}
		i++;
	}
	if (stck->sort == 0)
	{
		ft_free(stck);
		free_arr(stck->stc);
		exit (1);
	}
}

void	ft_three(t_stck *stck)
{
	if (stck->stack[0] < stck->stack[1])
	{
		if (stck->stack[0] > stck->stack[2])
		{
			ft_re_rotate_a(stck);
			ft_printf("rra\n");
		}
		else
		{
			ft_re_rotate_a(stck);
			ft_swap_a(stck);
			ft_printf("rra\n");
			ft_printf("sa\n");
		}
	}
	else if (stck->stack[1] < stck->stack[0])
		ft_three_two(stck);
}

void	ft_sorting(t_stck *stck)
{
	ft_push_to_b(stck);
	ft_push_to_b(stck);
	ft_printf("pb\npb\n");
	while (stck->a_count > 3)
	{
		stck->check = 0;
		ft_calculate(stck);
		ft_sort_stack(stck);
	}
	if (ft_check_sort_tree(stck))
		ft_sorted(stck);
	while (stck->b_count)
	{
		if (ft_check_min(stck->stack_b[0], stck))
			ft_sort_a_min(stck);
		else
		{
			ft_last_sort_a(stck);
			ft_push_to_a(stck);
			ft_printf("pa\n");
		}
	}
	ft_final_final(stck);
}
