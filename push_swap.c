/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:26:17 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/09/08 07:57:55 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorted(t_stck *stck)
{
	if (stck->a_count == 2)
	{
		ft_swap_a(stck);
		ft_printf("sa\n");
	}
	else
		ft_three(stck);
}

void	ft_string(int ac, char **av, t_stck *stck)
{
	int		i;
	char	*str;
	char	*tmp;
	char	*n;

	tmp = malloc(sizeof(char));
	tmp[0] = '\0';
	i = 1;
	while (i < ac)
	{
		str = ft_strjoin(av[i], " ");
		n = ft_strjoin(tmp, str);
		free(tmp);
		tmp = n;
		free(str);
		i++;
	}
	stck->stc = ft_split(tmp, ' ');
	ft_check_space(av, ac, stck);
	free(tmp);
}

void	ft_zero(t_stck *stck, int ac)
{
	stck->ac = ac - 1;
	stck->a_count = ac - 1;
	stck->b_count = 0;
	stck->sort = 0;
	stck->re_c = 0;
	stck->r_c = 0;
	stck->c = 0;
	stck->a = 0;
	stck->b = 0;
	stck->r_a = 0;
	stck->r_b = 0;
	stck->check = 0;
	stck->best = 0;
	stck->i = 0;
	stck->s_count = 0;
	stck->j = 0;
	stck->x = 0;
	stck->cont = 0;
	stck->max_c = 0;
	stck->atoi_c = 0;
	stck->sign = 1;
}

void	ft_error_convert(t_stck *stck)
{
	ft_check_int(stck);
	ft_check_int_min(stck);
	stck->stack = (int *)malloc(sizeof(int) * (stck->a_count));
	stck->stack_b = (int *)malloc(0);
	stck->c_stack = (int *)malloc(sizeof(int) * (stck->a_count));
	ft_convert_string(stck);
	ft_check_same(stck);
}

int	main(int ac, char **av)
{
	t_stck	stck;

	ft_zero(&stck, ac);
	if (ac > 1)
	{
		ft_check_null(ac, av);
		ft_string(ac, av, &stck);
		ft_error_convert(&stck);
		ft_check_sort(&stck);
		if (stck.ac == 3)
			ft_three(&stck);
		else if (stck.ac == 2)
		{
			ft_rotate_a(&stck);
			ft_printf("ra\n");
		}
		else
			ft_sorting(&stck);
		ft_free(&stck);
		free_arr(stck.stc);
	}
}
