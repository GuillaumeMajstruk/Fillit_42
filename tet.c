/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 07:47:26 by guillaume         #+#    #+#             */
/*   Updated: 2018/06/05 23:26:08 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		get_tet_size(const char *tet_str, int *height, int *width)
{
	t_iterator	it;
	t_bool		swap;

	it = 0;
	swap = FALSE;
	*height = 0;
	*width = 0;
	while (it < PARTS_NB)
	{
		if (tet_str[it] && tet_str[it] == TET_PART && swap == FALSE)
		{
			(*height)++;
			swap = TRUE;
		}
		if (tet_str[it] == ENDL)
			swap = FALSE;
		it++;
	}
	it = -1;
	while (++it <= 4)
	{
		if (tet_str[it] == TET_PART || tet_str[it + 5] == TET_PART ||
			tet_str[it + 10] == TET_PART || tet_str[it + 15] == TET_PART)
			(*width)++;
	}
}

t_point		*get_blocs(const char *tet_str)
{
	t_point		*bloc;
	t_iterator	str_it;
	t_iterator	b_it;

	if (!(bloc = (t_point*)malloc(sizeof(t_point) * 4)))
		bloc = NULL;
	str_it = 0;
	b_it = 0;
	while (str_it < PARTS_NB)
	{
		if (tet_str[str_it] == TET_PART)
		{
			bloc[b_it].x = str_it % 5;
			bloc[b_it].y = str_it / 5;
			b_it++;
		}
		str_it++;
	}
	return (bloc);
}

void		get_min_max_coord(const char *tet_str, t_point *min, t_point *max)
{
	t_iterator it;

	min->x = 3;
	min->y = 3;
	max->x = 0;
	max->y = 0;
	it = 0;
	while (it < PARTS_NB)
	{
		if (tet_str[it] == TET_PART)
		{
			if (it % 5 < min->x)
				min->x = it % 5;
			if (it / 5 < min->y)
				min->y = it / 5;
			if (it % 5 > max->x)
				max->x = it % 5;
			if (it / 5 > max->y)
				max->y = it / 5;
		}
		it++;
	}
}

int			push_back_tet(t_tet **tab, t_tet tet)
{
	static t_iterator	tet_count = 0;

	if (tet_count <= 25)
	{
		(*tab)[tet_count] = tet;
		tet_count++;
	}
	return (tet_count);
}

t_tet		create_tet(const char *tet_str)
{
	static char		letter = 'A';
	t_tet			tet;

	tet.letter = letter;
	tet.offset.x = 0;
	tet.offset.y = 0;
	get_tet_size(tet_str, &tet.height, &tet.width);
	get_min_max_coord(tet_str, &tet.min_point, &tet.max_point);
	tet.blocs = get_blocs(tet_str);
	letter++;
	return (tet);
}
