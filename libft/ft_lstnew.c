/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:20:16 by guillaume         #+#    #+#             */
/*   Updated: 2017/12/15 20:42:19 by guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *lst;

	lst = NULL;
	if (!(lst = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		lst->content_size = content_size;
		lst->content = ft_memalloc(content_size);
		ft_memcpy(lst->content, (void*)content, content_size);
	}
	else
	{
		lst->content = NULL;
		lst->content_size = 0;
	}
	lst->next = NULL;
	return (lst);
}
