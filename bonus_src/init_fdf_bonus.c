/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:15:40 by jeshin            #+#    #+#             */
/*   Updated: 2024/03/26 15:55:22 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	word_cnt(char *s, char c)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	if (s[i] && s[i] != c)
		cnt++;
	while (s[i])
	{
		if (s[i] == c && (s[i + 1] != c && s[i + 1] != 0))
			cnt++;
		i++;
	}
	return (cnt);
}

static int	is_fdf_file(char *file)
{
	char	*here;

	here = ft_strrchr(file, '.');
	if (!here)
		return (FALSE);
	if (ft_strncmp(here, ".fdf", 5))
		return (FALSE);
	return (TRUE);
}

static int	has_dq_same_len_all(t_dq *dq)
{
	t_node	*start;
	int		cnt;

	start = dq->head;
	cnt = word_cnt(start->data, ' ');
	start = start->next;
	while (start)
	{
		if (cnt != word_cnt(start->data, ' '))
		{
			clear_dq(dq);
			return (FALSE);
		}
		start = start->next;
	}
	return (TRUE);
}

static int	push_contents_to_dq(char *file, t_dq *dq)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	while (TRUE)
	{
		line = get_next_line(fd);
		if (line == 0)
			break ;
		push_back_dq(dq, line);
	}
	close(fd);
	return (EXIT_SUCCESS);
}

int	init_fdf(int ac, char **av, t_dq *dq)
{
	if (ac != 2 || is_fdf_file(av[1]) == FALSE)
		return (EXIT_FAILURE);
	init_dq(dq);
	if (push_contents_to_dq(av[1], dq))
		return (EXIT_FAILURE);
	if (has_dq_same_len_all(dq) == FALSE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
