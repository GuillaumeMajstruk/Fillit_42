/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 22:06:18 by guillaume         #+#    #+#             */
/*   Updated: 2017/12/26 13:03:18 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_word_count(char const *s, char separator)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != separator && (i == 0 || s[i - 1] == separator))
			count++;
		i++;
	}
	return (count);
}

static	int		ft_word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static	char	*ft_word_cpy(char const *s, char c)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = NULL;
	cpy = (char*)malloc(sizeof(char) * (ft_word_len(s, c) + 1));
	if (cpy)
	{
		while (s[i] && s[i] != c)
		{
			cpy[i] = s[i];
			i++;
		}
		cpy[i] = '\0';
	}
	return (cpy);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	tab = NULL;
	if (!s)
		return (tab);
	tab = (char**)malloc(sizeof(char*) * (ft_word_count(s, c) + 1));
	if (tab)
	{
		while (s[i])
		{
			if (s[i] != c && (i == 0 || s[i - 1] == c))
				tab[j++] = ft_word_cpy(s + i, c);
			i++;
		}
		tab[j] = NULL;
	}
	return (tab);
}
