/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_p_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 23:48:14 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/09/08 06:47:14 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_push_to_b_bonus(t_stack *stck)
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
		ft_allocate_mem_p_bonus(stck, ar_a, ar_b);
	}
}

void	ft_command_p(t_stack *stck)
{
	if (stck->str[1] == 'a')
		ft_push_to_a_bonus(stck);
	else if (stck->str[1] == 'b')
		ft_push_to_b_bonus(stck);
	else
	{
		write(2, "Error\n", 6);
		exit (1);
	}
}
