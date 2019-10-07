/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:59:24 by guillaume         #+#    #+#             */
/*   Updated: 2017/12/26 13:27:29 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (*haystack && ft_strlen(needle) == 0)
		return ((char*)haystack);
	if (len < (size_t)ft_strlen(needle))
		return (NULL);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] && needle[j] && haystack[i + j] == needle[j]
		&& (i + j) < len)
			j++;
		if (!needle[j] || j == len)
			return ((char*)haystack + i);
		i++;
	}
	return (NULL);
}
