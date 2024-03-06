/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:15:40 by jeshin            #+#    #+#             */
/*   Updated: 2024/03/06 19:22:40 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_tab(char **tab)
{
	int i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

static int	is_fdf_file(char *file)
{
	char **splited;

	if (!ft_strnstr(file, ".", ft_strlen(file)))
		return (0);
	splited = ft_split(file, '.');
	if (ft_strncmp(splited[1], "fdf", 4) || splited[2] != 0 )
	{
		free_tab(splited);
		return (0);
	}
	free_tab(splited);
	return (1);
}

int init(int ac, char **av, t_dq *dq)
{
	int	fd;
	size_t	size;
	char *line;

	if (ac != 2 || !is_fdf_file(av[1]))
		return (1);
	fd = open(av[1],O_RDONLY);
	if (!fd)
		return (1);
	init_dq(dq);
	while (1)
	{
		line = get_next_line(fd);
		if (line == 0)
			break;
		push_back_dq(dq, line);
	}
	prt_all_dq(dq);
	return (0);
}
