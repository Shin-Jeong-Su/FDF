/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_deque2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:28:30 by jeshin            #+#    #+#             */
/*   Updated: 2024/03/08 19:24:14 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_deque.h"

void	pop_front_dq(t_dq *dq)
{
	t_node	*tmp;

	if (is_empty_dq(dq))
		return ;
	tmp = dq->head;
	dq->head = dq->head->next;
	free(tmp->data);
	free(tmp);
	if (dq->head == NULL)
		dq->tail = NULL;
	else
		dq->head->prev = NULL;
	dq->size--;
}

void	pop_back_dq(t_dq *dq)
{
	t_node	*tmp;

	if (is_empty_dq(dq))
		return ;
	tmp = dq->tail;
	dq->tail = dq->tail->prev;
	free(tmp->data);
	free(tmp);
	if (dq->tail == NULL)
		dq->head = NULL;
	else
		dq->tail->next = 0;
	dq->size--;
}

void	clear_dq(t_dq *dq)
{
	while (!is_empty_dq(dq))
		pop_back_dq(dq);
}

char	*front_dq(t_dq *dq)
{
	if (is_empty_dq(dq))
		return (0);
	return (dq->head->data);
}

char	*back_dq(t_dq *dq)
{
	if (is_empty_dq(dq))
		return (0);
	return (dq->tail->data);
}
