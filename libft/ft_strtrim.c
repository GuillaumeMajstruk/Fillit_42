/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 21:19:24 by guillaume         #+#    #+#             */
/*   Updated: 2017/12/26 13:01:50 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_find_start(char const *s)
{
	unsigned int	i;

	i = 0;
	if (s)
	{
		while (ft_isspacetrim(s[i]))
			i++;
	}
	return (i);
}

static unsigned int	ft_find_last(char const *s)
{
	unsigned int i;
	unsigned int last;

	i = 0;
	last = 0;
	if (s)
	{
		while (i < ft_strlen(s))
		{
			if (!ft_isspacetrim(s[i]))
				last = i;
			i++;
		}
	}
	return (last);
}

char				*ft_strtrim(char const *s)
{
	unsigned int		start;
	unsigned int		last_index;
	unsigned int		i;
	char				*str;

	start = ft_find_start(s);
	last_index = ft_find_last(s);
	i = 0;
	str = NULL;
	if (!s)
		return (NULL);
	if (start == ft_strlen(s))
	{
		str = ft_strnew(1);
		return (str);
	}
	if (!(str = ft_strsub(s, start, last_index - start + 1)))
		return (NULL);
	return (str);
}
