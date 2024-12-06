/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func_ro.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 03:30:46 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/08/04 23:41:28 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_stck *stck)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	if (stck->a_count > 1)
	{
		tmp = stck->stack[0];
		while (i < (stck->a_count - 1))
		{
			stck->stack[i] = stck->stack[i + 1];
			i++;
		}
		stck->stack[stck->a_count - 1] = tmp;
	}
}

void	ft_rotate_b(t_stck *stck)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	if (stck->b_count > 1)
	{
		tmp = stck->stack_b[0];
		while (i < (stck->b_count - 1))
		{
			stck->stack_b[i] = stck->stack_b[i + 1];
			i++;
		}
		stck->stack_b[stck->b_count - 1] = tmp;
	}
}

void	ft_rotate_ab(t_stck *stck)
{
	ft_rotate_a(stck);
	ft_rotate_b(stck);
}

void	ft_re_rotate_a(t_stck *stck)
{
	int	i;
	int	tmp;

	tmp = stck->stack[stck->a_count - 1];
	i = stck->a_count - 2;
	if (stck->a_count > 1)
	{
		while (i >= 0)
		{
			stck->stack[i + 1] = stck->stack[i];
			i--;
		}
		stck->stack[0] = tmp;
	}
}

void	ft_re_rotate_b(t_stck *stck)
{
	int	i;
	int	tmp;

	tmp = stck->stack_b[stck->b_count - 1];
	i = stck->b_count - 2;
	if (stck->b_count > 1)
	{
		while (i >= 0)
		{
			stck->stack_b[i + 1] = stck->stack_b[i];
			i--;
		}
		stck->stack_b[0] = tmp;
	}
}
