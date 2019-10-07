/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 23:21:46 by gmajstru          #+#    #+#             */
/*   Updated: 2018/06/05 23:24:28 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	set_in_corner(t_tet *tet, const char *map)
{
	t_iterator it;
	t_iterator jt;

	it = 0;
	jt = 0;
	while (it < PARTS_NB)
	{
		if (map[it] == TET_PART)
		{
			tet->blocs[jt].x = (it % 5) - tet->min_point.x;
			tet->blocs[jt].y = (it / 5) - tet->min_point.y;
			jt++;
		}
		it++;
	}
}

t_bool	check_tet_pos(char *map, t_tet tet)
{
	t_iterator it;

	it = 0;
	while (it < 4)
	{
		if (map[((tet.blocs[it].y + tet.offset.y) * 16) +
		(tet.blocs[it].x + tet.offset.x)] != TET_EMPTY)
			return (FALSE);
		it++;
	}
	return (TRUE);
}

void	del_tet(char *map, t_tet *tet)
{
	t_iterator it;

	it = 0;
	while (it < 4)
	{
		map[((tet->blocs[it].y + tet->offset.y) * 16) +
		(tet->blocs[it].x + tet->offset.x)] = TET_EMPTY;
		it++;
	}
}

void	update_map(char *map, t_tet tet)
{
	t_iterator it;

	it = 0;
	while (it < 4)
	{
		map[((tet.blocs[it].y + tet.offset.y) * 16) +
		(tet.blocs[it].x + tet.offset.x)] = tet.letter;
		it++;
	}
}

int		mv_tet(char *map, t_tet *tet, int size, int tab_size)
{
	if (tab_size == 0)
		return (1);
	tet->offset.y = 0;
	while (tet->offset.y <= size - tet->height)
	{
		tet->offset.x = 0;
		while (tet->offset.x <= size - tet->width)
		{
			if (check_tet_pos(map, *tet))
			{
				update_map(map, *tet);
				if (mv_tet(map, tet + 1, size, tab_size - 1))
					return (TRUE);
				del_tet(map, tet);
			}
			tet->offset.x++;
		}
		tet->offset.y++;
	}
	return (FALSE);
}
