/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:40:33 by jquinde-          #+#    #+#             */
/*   Updated: 2025/02/22 17:40:33 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

t_queue queue_new (void)
{
    t_queue queue;

    queue.head = NULL;
    queue.tail = NULL;
    return (queue);
}

int queue_empty (t_queue queue)
{
    return (queue.head == NULL);
}

void queue_put (t_queue *queue, void *x)
{
    t_list  *new_node;

    new_node = ft_lstnew(x);
    if (new_node == NULL)
        return ;
    if (queue->head == NULL)
    {
        queue->head = new_node;
        queue->tail = new_node;
    }
    else
    {
        queue->tail->next = new_node;
        queue->tail = queue->tail->next;
    }
}

void *queue_get (t_queue *queue)
{
    t_list	*node;
    void	*element;	

	node = queue->head;
	element = node->content;
	queue->head = node->next;
	free(node);
	return (element);
}

void queue_free (t_queue *queue)
{
	ft_lstclear(&queue->head, free);
	queue->tail = NULL;
}
