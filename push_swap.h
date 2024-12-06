/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:20:07 by ahmtemel          #+#    #+#             */
/*   Updated: 2023/09/08 07:58:49 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <stdlib.h>
# include "./printf/ft_printf.h"

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
}	t_stck;

void	ft_check_int(t_stck *stck);
void	ft_check_int_min(t_stck *stck);
void	ft_convert_string(t_stck *stck);
void	ft_check_same(t_stck *stck);
void	ft_atoi_max(const char *str, t_stck *stck);
void	ft_swap_a(t_stck *stck);
void	ft_swap_b(t_stck *stck);
void	ft_swap_ab(t_stck *stck);
void	ft_push_to_a(t_stck *stck);
void	ft_push_to_b(t_stck *stck);
void	ft_allocate_mem_p(t_stck *stck, int *ar_a, int *ar_b);
void	ft_rotate_a(t_stck *stck);
void	ft_rotate_b(t_stck *stck);
void	ft_re_rotate_b(t_stck *stck);
void	ft_re_rotate_a(t_stck *stck);
void	ft_rotate_ab(t_stck *stck);
void	ft_re_rotate_ab(t_stck *stck);
void	ft_three(t_stck *stck);
void	ft_sorting(t_stck *stck);
void	ft_check_sort(t_stck *stck);
int		ft_min_max_check(t_stck *stck, int a);
int		ft_cal_rot(t_stck *stck, int c);
void	ft_cal_a(t_stck *stck, int *i, int *r_i, int c);
void	ft_cal_b(t_stck *stck, int *j, int *r_j, int m);
int		ft_cal_rot_man(t_stck *stck, int c);
void	ft_to_stack(t_stck *stck, int j, int r_i, int r_j);
void	ft_zero_two(int *i, int *j, int *r_i, int *r_j);
void	ft_final_sort(t_stck *stck);
void	ft_find_best(t_stck *stck);
void	ft_sort_stack(t_stck *stck);
int		ft_find_max(t_stck *stck);
void	ft_sort_a_three(t_stck *stck);
void	ft_last_sort_a(t_stck *stck);
void	ft_free(t_stck *stck);
void	ft_final_final(t_stck *stck);
void	free_arr(char **arr);
void	ft_check_space(char **stc, int ac, t_stck *stck);
void	ft_check_null(int ac, char **av);
int		ft_check_sort_tree(t_stck *stck);
int		ft_find_min_a(t_stck *stck);
void	ft_sort_a_min(t_stck *stck);
int		ft_check_min(int c, t_stck *stck);
void	ft_sorted(t_stck *stck);
#endif
