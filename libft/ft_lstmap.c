/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 16:31:45 by guillaume         #+#    #+#             */
/*   Updated: 2017/12/26 12:59:16 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *res;
	t_list *tmp;

	res = NULL;
	tmp = NULL;
	if (!lst || !f)
		return (res);
	while (lst)
	{
		tmp = (*f)(lst);
		ft_lst_pushback(&res, ft_lstnew(tmp->content, tmp->content_size));
		lst = lst->next;
	}
	return (res);
}
