/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:58:47 by guillaume         #+#    #+#             */
/*   Updated: 2017/11/26 15:26:19 by guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;

	i = 0;
	str = (const unsigned char*)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((unsigned char*)(s) + i);
		i++;
	}
	return (NULL);
}
