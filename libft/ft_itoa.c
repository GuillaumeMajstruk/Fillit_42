/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 16:11:58 by guillaume         #+#    #+#             */
/*   Updated: 2017/12/27 14:03:49 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	long int	big;
	int			len;

	big = n;
	len = 0;
	if (n < 0)
	{
		len++;
		big = -n;
	}
	while (big != big % 10)
	{
		big = (big - big % 10) / 10;
		len++;
	}
	len++;
	return (len);
}

char		*ft_itoa(int n)
{
	char		*res;
	int			i;
	int			len;
	long int	big;

	i = 0;
	len = ft_numlen(n);
	big = n;
	if (!(res = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		big *= -1;
	}
	while (i < (n < 0 ? len - 1 : len))
	{
		res[len - i - 1] = (big % 10) + '0';
		big = (big - big % 10) / 10;
		i++;
	}
	res[len] = '\0';
	return (res);
}
