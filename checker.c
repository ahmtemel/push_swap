/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:25:49 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/09/08 07:50:00 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_string_bonus(int ac, char **av, t_stack *stck)
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
	ft_check_space_bonus(av, ac, stck);
	free(tmp);
}

void	ft_check_null_bonus(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
			j++;
		if (j == 0)
		{
			write(2, "Error\n", 6);
			exit (1);
		}
		i++;
	}
}

void	ft_zero_bonus(t_stack *stck, int ac)
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

void	ft_error_convert_bonus(t_stack *stck)
{
	ft_check_int_bonus(stck);
	ft_check_int_min_bonus(stck);
	stck->stack = (int *)malloc(sizeof(int) * (stck->a_count));
	stck->stack_b = (int *)malloc(0);
	stck->c_stack = (int *)malloc(sizeof(int) * (stck->a_count));
	ft_convert_string_bonus(stck);
	ft_check_same_bonus(stck);
}

int	main(int ac, char **av)
{
	t_stack	stck;

	if (ac > 1)
	{
		ft_zero_bonus(&stck, ac);
		ft_check_null_bonus(ac, av);
		ft_string_bonus(ac, av, &stck);
		ft_error_convert_bonus(&stck);
		while (1)
			ft_get_command_bonus(&stck);
	}
}
