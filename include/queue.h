/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:14:26 by jquinde-          #+#    #+#             */
/*   Updated: 2025/02/22 17:14:26 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef QUEUE_H
# define QUEUE_H
typedef struct s_queue
{
	t_list *head;
	t_list *tail;
}				t_queue;


t_queue queue_new (void);
int queue_empty (t_queue queue);
void queue_put (t_queue *queue, void *x);
void *queue_get (t_queue *stk);
void queue_free (t_queue *queue);

#endif