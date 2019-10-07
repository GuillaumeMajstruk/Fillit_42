/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 13:52:18 by gmajstru          #+#    #+#             */
/*   Updated: 2017/12/18 15:31:41 by guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*conc;
	size_t	tot_len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	conc = NULL;
	if (!s1 || !s2)
		return (NULL);
	tot_len = (size_t)(ft_strlen(s1) + ft_strlen(s2));
	conc = (char*)malloc(sizeof(char) * tot_len + 1);
	if (conc)
	{
		while (i < ft_strlen(s1))
			conc[j++] = s1[i++];
		i = 0;
		while (i < ft_strlen(s2))
			conc[j++] = s2[i++];
		conc[j] = '\0';
	}
	return (conc);
}
