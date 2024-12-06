/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 03:01:42 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/09/07 23:29:20 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stck *stck)
{
	free(stck->stack);
	free(stck->stack_b);
	free(stck->c_stack);
}

void	ft_swap_a(t_stck *stck)
{
	int	tmp;

	tmp = 0;
	if (stck->a_count >= 2)
	{
		tmp = stck->stack[0];
		stck->stack[0] = stck->stack[1];
		stck->stack[1] = tmp;
	}
}

void	ft_swap_b(t_stck *stck)
{
	int	tmp;

	tmp = 0;
	if (stck->b_count >= 2)
	{
		tmp = stck->stack_b[0];
		stck->stack_b[0] = stck->stack_b[1];
		stck->stack_b[1] = tmp;
	}
}

void	ft_swap_ab(t_stck *stck)
{
	ft_swap_a(stck);
	ft_swap_b(stck);
}

void	ft_push_to_a(t_stck *stck)
{
	int	i;
	int	*ar_a;
	int	*ar_b;

	i = 1;
	if (stck->b_count > 0)
	{
		ar_a = (int *)malloc(sizeof(int) * (stck->a_count + 1));
		ar_b = (int *)malloc(sizeof(int) * (stck->b_count - 1));
		stck->a_count++;
		stck->b_count--;
		ar_a[0] = stck->stack_b[0];
		while (i < stck->a_count)
		{
			ar_a[i] = stck->stack[i - 1];
			i++;
		}
		i = 0;
		while (i < stck->b_count)
		{
			ar_b[i] = stck->stack_b[i + 1];
			i++;
		}
		ft_allocate_mem_p(stck, ar_a, ar_b);
	}
}
