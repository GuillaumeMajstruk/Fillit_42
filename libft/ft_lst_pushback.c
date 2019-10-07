/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pushback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:27:08 by guillaume         #+#    #+#             */
/*   Updated: 2017/12/18 14:37:33 by guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_pushback(t_list **lbegin, t_list *lnew)
{
	t_list *lst;

	lst = *lbegin;
	if (!lst)
		*lbegin = lnew;
	else
	{
		while (lst->next)
			lst = lst->next;
		lst->next = lnew;
	}
}
