/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:52:22 by gmajstru          #+#    #+#             */
/*   Updated: 2017/11/28 17:53:29 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*n;
	size_t		i;

	i = 0;
	if (!(n = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
		n[i++] = '\0';
	n[i] = '\0';
	return (n);
}
