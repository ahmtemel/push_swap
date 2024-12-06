/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:57:01 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/09/08 09:23:08 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_command_s(t_stack *stck)
{
	if (stck->str[1] == 'a')
		ft_swap_a_bonus(stck);
	else if (stck->str[1] == 'b')
		ft_swap_b_bonus(stck);
	else if (stck->str[1] == 's')
		ft_swap_ab_bonus(stck);
	else
	{
		write(2, "Error\n", 6);
		exit (1);
	}
}

void	ft_command_r_two(t_stack *stck)
{
	if (stck->str[1] == 'r' && stck->str[2] == 'a')
		ft_re_rotate_a_bonus(stck);
	else if (stck->str[1] == 'r' && stck->str[2] == 'b')
		ft_re_rotate_b_bonus(stck);
	else if (stck->str[1] == 'r' && stck->str[2] == 'r')
		ft_re_rotate_ab_bonus(stck);
	else
	{
		write(2, "Error\n", 6);
		exit (1);
	}
}

void	ft_command_r(t_stack *stck)
{
	if (ft_strlen(stck->str) == 3)
	{
		if (stck->str[1] == 'a')
			ft_rotate_a_bonus(stck);
		else if (stck->str[1] == 'b')
			ft_rotate_b_bonus(stck);
		else if (stck->str[1] == 'r')
			ft_rotate_ab_bonus(stck);
		else
		{
			write(2, "Error\n", 6);
			exit (1);
		}
	}
	else
		ft_command_r_two(stck);
}

void	ft_check_command_bonus(t_stack *stck)
{
	int	i;

	i = ft_strlen(stck->str);
	if (i < 3 || i > 4)
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	else
	{
		if (stck->str[0] == 'r')
			ft_command_r(stck);
		else if (stck->str[0] == 's' && i == 3)
			ft_command_s(stck);
		else if (stck->str[0] == 'p' && i == 3)
			ft_command_p(stck);
		else
		{
			write(2, "Error\n", 6);
			exit (1);
		}
	}
}

void	ft_get_command_bonus(t_stack *stck)
{
	stck->str = get_next_line(0);
	if (stck->str == 0)
	{
		ft_check_sort_a_bonus(stck);
		if (stck->sort == -1 || stck->b_count != 0)
			ft_printf("KO\n");
		else if (stck->sort == 0 && stck->b_count == 0)
			ft_printf("OK\n");
		exit (1);
	}
	else
		ft_check_command_bonus(stck);
	free(stck->str);
}
