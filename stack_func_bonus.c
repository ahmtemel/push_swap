/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 23:24:45 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/09/07 23:55:59 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap_a_bonus(t_stack *stck)
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

void	ft_swap_b_bonus(t_stack *stck)
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

void	ft_swap_ab_bonus(t_stack *stck)
{
	ft_swap_a_bonus(stck);
	ft_swap_b_bonus(stck);
}

void	ft_push_to_a_bonus(t_stack *stck)
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
		ft_allocate_mem_p_bonus(stck, ar_a, ar_b);
	}
}

void	ft_allocate_mem_p_bonus(t_stack *stck, int *ar_a, int *ar_b)
{
	free(stck->stack);
	free(stck->stack_b);
	stck->stack = ar_a;
	stck->stack_b = ar_b;
}
