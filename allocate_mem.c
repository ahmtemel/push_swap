/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 03:58:16 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/09/07 23:27:45 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_re_rotate_ab(t_stck *stck)
{
	ft_re_rotate_a(stck);
	ft_re_rotate_b(stck);
}

void	ft_allocate_mem_p(t_stck *stck, int *ar_a, int *ar_b)
{
	free(stck->stack);
	free(stck->stack_b);
	stck->stack = ar_a;
	stck->stack_b = ar_b;
}
