/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 07:46:01 by guillaume         #+#    #+#             */
/*   Updated: 2018/05/25 07:46:19 by guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_bool	check_input(int rd_ret, char c, int **err_code)
{
	if (rd_ret != BUFFSIZE && c != ENDL)
	{
		**err_code = ERROR;
		return (TRUE);
	}
	if (rd_ret == 0)
		return (TRUE);
	return (FALSE);
}

t_list	*read_file(const char *f_name, int *err_code)
{
	int		fd;
	int		ret[2];
	char	buffer[BUFFSIZE + 1];
	char	buff_endl[1];
	t_list	*tet_lst;

	fd = open(f_name, O_RDONLY);
	tet_lst = NULL;
	while ((ret[0] = read(fd, buffer, BUFFSIZE)))
	{
		if (check_input(ret[0], buff_endl[0], &err_code))
			break ;
		buffer[ret[0]] = '\0';
		ft_lst_pushback(&tet_lst, ft_lstnew(buffer, BUFFSIZE));
		ret[1] = read(fd, buff_endl, 1);
	}
	if (ret[1] == TRUE || *err_code == ERROR || !tet_lst)
	{
		*err_code = ERROR;
		ft_putendl("error");
	}
	return (tet_lst);
}
