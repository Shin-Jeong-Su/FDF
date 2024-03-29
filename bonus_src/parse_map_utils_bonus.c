/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:47:06 by jeshin            #+#    #+#             */
/*   Updated: 2024/03/26 15:55:58 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	has_color_value(t_dq *dq)
{
	t_node	*start;
	char	*line;

	start = dq->head;
	while (start)
	{
		line = start->data;
		if (ft_strchr(line, ','))
			return (TRUE);
		start = start->next;
	}
	return (FALSE);
}

static void	get_rgb(t_clr *clr)
{
	if (clr->i < 2)
	{
		clr->r *= 16;
		clr->r += clr->j;
	}
	else if (clr->i < 4)
	{
		clr->g *= 16;
		clr->g += clr->j;
	}
	else if (clr->i < 6)
	{
		clr->b *= 16;
		clr->b += clr->j;
	}
}

unsigned int	cvrt_str_to_color(char *s)
{
	char	*start;
	t_clr	clr;

	if (s == 0 && *s == 0)
		return (EXIT_FAILURE);
	clr.set = "0123456789ABCDEF";
	start = ft_strnstr(s, "0x", ft_strlen(s));
	if (start == 0)
		return (EXIT_SUCCESS);
	start += 2;
	clr.i = -1;
	clr.r = 0;
	clr.g = 0;
	clr.b = 0;
	while (start[++(clr.i)])
	{
		clr.j = -1;
		while (clr.set[++(clr.j)])
		{
			if (clr.set[(clr.j)] == start[(clr.i)])
				get_rgb(&clr);
		}
	}
	clr.color = (clr.r << 16) + (clr.g << 8) + (clr.b);
	return (clr.color);
}
