/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmtemel <ahmtemel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:38:29 by ahmtemel          #+#    #+#             */
/*   Updated: 2022/10/21 15:48:24 by ahmtemel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*iter;

	if (!lst || !del || !*lst)
		return ;
	iter = (*lst);
	while (iter != NULL)
	{
		iter = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		(*lst) = iter;
	}
}
