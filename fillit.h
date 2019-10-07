/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 07:45:47 by guillaume         #+#    #+#             */
/*   Updated: 2018/06/29 15:44:33 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

# define TRUE 		1
# define FALSE		0
# define ERROR		-1
# define TET_PART 	'#'
# define TET_EMPTY 	'.'
# define ENDL		'\n'
# define PARTS_NB	20
# define BUFFSIZE	20

typedef int			t_iterator;
typedef int			t_bool;
typedef struct		s_point
{
	int	x;
	int	y;
}					t_point;

typedef struct		s_tet
{
	char		letter;
	int			width;
	int			height;
	t_point		*blocs;
	t_point		offset;
	t_point		min_point;
	t_point		max_point;
}					t_tet;

void				check_argc(int argc);
t_bool				check_block_count (char const *tet_str);
t_bool				check_endl (char const *tet_str);
t_bool				tet_is_valide(char const *tet_str);
t_bool				check_input(int rd_ret, char c, int **err_code);
t_list				*read_file(const char *f_name, int *err_code);
void				get_tet_size(const char *tet_str, int *height, int *width);
t_point				*get_blocs(const char *tet_str);
void				get_min_max_coord(const char *tet_str, t_point *min,
		t_point *max);
int					push_back_tet(t_tet **tab, t_tet tet);
t_tet				create_tet(const char *tet_str);
void				set_in_corner(t_tet *tet, const char *map);
t_bool				check_tet_pos(char *map, t_tet tet);
void				del_tet(char *map, t_tet *tet);
void				update_map(char *map, t_tet tet);
int					mv_tet(char *map, t_tet *tet, int size, int tab_size);
char				*init_map(char *map);
void				print_map(char *map, int size);
int					init(t_list *list, t_tet **tab, int *i);
void				free_rsc(t_list **list, t_tet **tab, char **map);

#endif
