/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:31:03 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/09/08 07:51:10 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "./libft/libft.h"
# include <stdlib.h>
# include "./printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include <unistd.h>

typedef struct ss_list
{
	int		*stack;
	int		*stack_b;
	int		*c_stack;
	char	**stc;
	int		ac;
	int		a_count;
	int		b_count;
	int		sort;
	int		re_c;
	int		r_c;
	int		c;
	int		a;
	int		b;
	int		r_a;
	int		r_b;
	int		check;
	int		best;
	int		i;
	int		s_count;
	int		j;
	int		x;
	int		cont;
	int		max_c;
	int		atoi_c;
	int		sign;
	char	*str;
}	t_stack;

void	ft_check_space_bonus(char **stc, int ac, t_stack *stck);
void	ft_check_int_min_bonus(t_stack *stck);
void	ft_check_int_bonus(t_stack *stck);
void	ft_convert_string_bonus(t_stack *stck);
void	ft_check_same_bonus(t_stack *stck);
void	free_arr_bonus(char **arr);
void	ft_free_bonus(t_stack *stck);
void	ft_atoi_max_bonus(const char *str, t_stack *stck);
void	ft_get_command_bonus(t_stack *stck);
void	ft_re_rotate_ab_bonus(t_stack *stck);
void	ft_swap_a_bonus(t_stack *stck);
void	ft_swap_b_bonus(t_stack *stck);
void	ft_swap_ab_bonus(t_stack *stck);
void	ft_push_to_a_bonus(t_stack *stck);
void	ft_allocate_mem_p_bonus(t_stack *stck, int *ar_a, int *ar_b);
void	ft_allocate_mem_p_bonus(t_stack *stck, int *ar_a, int *ar_b);
void	ft_rotate_a_bonus(t_stack *stck);
void	ft_rotate_b_bonus(t_stack *stck);
void	ft_rotate_ab_bonus(t_stack *stck);
void	ft_re_rotate_a_bonus(t_stack *stck);
void	ft_re_rotate_b_bonus(t_stack *stck);
void	ft_command_p(t_stack *stck);
void	ft_check_sort_a_bonus(t_stack *stck);

#endif
