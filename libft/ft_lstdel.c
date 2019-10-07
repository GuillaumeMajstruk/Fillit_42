/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 21:01:30 by guillaume         #+#    #+#             */
/*   Updated: 2017/12/26 12:58:48 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*first;
	t_list	*sec;

	first = *alst;
	if (!alst)
		return ;
	while (first)
	{
		sec = first;
		first = first->next;
		ft_lstdelone(&sec, del);
	}
	ft_lstdelone(&sec, del);
	*alst = NULL;
}
