/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort_a_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 00:10:50 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/09/08 00:14:57 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_check_sort_a_bonus(t_stack *stck)
{
	int	i;
	int	j;
	int	check;

	i = 0;
	stck->sort = 0;
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
}
