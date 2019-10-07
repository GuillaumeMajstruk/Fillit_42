/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 13:02:44 by guillaume         #+#    #+#             */
/*   Updated: 2017/11/26 16:20:31 by guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	while (len-- > 0)
		((unsigned char*)dst)[len] = ((unsigned char*)src)[len];
	return (dst);
}
