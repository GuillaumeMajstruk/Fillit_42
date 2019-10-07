/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:34:36 by gmajstru          #+#    #+#             */
/*   Updated: 2017/11/28 17:53:47 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	char *d;

	if (len != 0)
	{
		d = dest;
		while (len != 0)
		{
			if ((*d++ = *src++) == 0)
			{
				while (--len != 0)
					*d++ = 0;
				break ;
			}
			len--;
		}
	}
	return (dest);
}
