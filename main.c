/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:40:14 by jeshin            #+#    #+#             */
/*   Updated: 2024/03/05 15:16:30 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"
#include <stdio.h>

int	init(int ac, char **av);
int main(int argc, char **argv)
{
	if (init(argc, argv))
	{
		//error
		return (1);
	}
}

int init(int ac, char **av)
{
	int	fd;
	char	*line;

	if (ac != 2)
		return (1);
	fd = open(av[1],O_RDONLY);
	if (!fd)
		return (1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == 0)
			break;
		printf("%s",line);
	}
	return (0);
}