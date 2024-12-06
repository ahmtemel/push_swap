/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:38:31 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/08/12 09:48:08 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_a_min(t_stck *stck)
{
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
	ft_push_to_a(stck);
	ft_rotate_a(stck);
	ft_printf("pa\nra\n");
}

int	ft_find_min_a(t_stck *stck)
{
	int	c;
	int	i;
	int	r;

	c = stck->stack[0];
	i = 1;
	r = 0;
	while (i < stck->a_count)
	{
		if (stck->stack[i] < c)
		{
			c = stck->stack[i];
			r = i;
		}
		i++;
	}
	return (r);
}

void	ft_push_to_b(t_stck *stck)
{
	int	i;
	int	*ar_a;
	int	*ar_b;

	i = 1;
	if (stck->a_count > 0)
	{
		ar_a = (int *)malloc(sizeof(int) * (stck->a_count - 1));
		ar_b = (int *)malloc(sizeof(int) * (stck->b_count + 1));
		stck->a_count--;
		stck->b_count++;
		ar_b[0] = stck->stack[0];
		while (i < stck->b_count)
		{
			ar_b[i] = stck->stack_b[i - 1];
			i++;
		}
		i = 0;
		while (i < stck->a_count)
		{
			ar_a[i] = stck->stack[i + 1];
			i++;
		}
		ft_allocate_mem_p(stck, ar_a, ar_b);
	}
}
