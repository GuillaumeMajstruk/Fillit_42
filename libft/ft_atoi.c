/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:27:36 by guillaume         #+#    #+#             */
/*   Updated: 2017/11/23 10:42:01 by guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int isneg;
	int val;

	i = 0;
	isneg = 0;
	val = 0;
	while (ft_isspace(str[i]))
		i++;
	isneg = (str[i] == '-') ? 1 : 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit((int)str[i]))
		val = val * 10 + (str[i++] - '0');
	if (isneg == 1)
		return (-val);
	else
		return (val);
}
