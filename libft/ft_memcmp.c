/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:29:20 by guillaume         #+#    #+#             */
/*   Updated: 2017/11/26 15:58:23 by guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char uc1;
	unsigned char uc2;

	uc1 = 0;
	uc2 = 0;
	while (n != 0)
	{
		uc1 = *(unsigned char*)s1;
		uc2 = *(unsigned char*)s2;
		if (uc1 != uc2)
			return (uc1 - uc2);
		n--;
		s1++;
		s2++;
	}
	return (0);
}
