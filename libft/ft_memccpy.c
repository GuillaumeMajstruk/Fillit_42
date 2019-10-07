/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 12:26:02 by guillaume         #+#    #+#             */
/*   Updated: 2017/12/19 17:24:23 by guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	d = (unsigned char*)dst;
	s = (const unsigned char*)src;
	while (i < n)
	{
		*d = *s;
		if (*s == (unsigned char)c)
			return (dst + i + 1);
		i++;
		d++;
		s++;
	}
	return (NULL);
}
