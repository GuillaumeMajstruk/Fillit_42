/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 07:45:26 by guillaume         #+#    #+#             */
/*   Updated: 2018/06/29 15:46:30 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*init_map(char *map)
{
	t_iterator	it;

	it = 0;
	if (!(map = (char *)malloc(sizeof(char) * 16 * 16 + 1)))
		return (NULL);
	while (it <= (16 * 16 - 1))
	{
		map[it] = '.';
		it++;
	}
	map[it] = '\0';
	return (map);
}

void	print_map(char *map, int size)
{
	t_iterator	it;
	t_iterator	jt;

	it = 0;
	while (it < size)
	{
		jt = 0;
		while (jt < size)
		{
			ft_putchar(map[(it * 16) + jt]);
			jt++;
		}
		ft_putchar('\n');
		it++;
	}
}

int		init(t_list *list, t_tet **tab, int *i)
{
	t_tet	tet;

	if (*i == -1)
	{
		ft_putendl("error");
		return (0);
	}
	while (list)
	{
		if (tet_is_valide((char *)list->content))
		{
			tet = create_tet((char *)list->content);
			set_in_corner(&tet, (char *)list->content);
			*i = push_back_tet(*(&tab), tet);
		}
		else if (!tet_is_valide((char *)list->content) || *i > 25)
		{
			ft_putendl("error");
			return (FALSE);
		}
		list = list->next;
	}
	return (TRUE);
}

void	free_rsc(t_list **list, t_tet **tab, char **map)
{
	free(*list);
	free(*tab);
	free(*map);
}

int		main(int argc, char *argv[])
{
	int		i;
	int		size;
	t_tet	*tab;
	t_list	*list;
	char	*map;

	check_argc(argc);
	i = 0;
	if (!(tab = (t_tet *)malloc(sizeof(t_tet) * 26)))
		tab = NULL;
	list = NULL;
	list = read_file(argv[1], &i);
	map = NULL;
	map = init_map(map);
	if (i == ERROR || !init(list, &tab, &i) || argc != 2)
		return (ERROR);
	size = (tab[0].height > tab[0].width ? tab[0].height : tab[0].width);
	while (!mv_tet(map, &tab[0], size, i))
	{
		init_map(map);
		size++;
	}
	print_map(map, size);
	free_rsc(&list, &tab, &map);
	return (0);
}
