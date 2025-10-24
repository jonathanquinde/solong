/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:03:38 by jquinde-          #+#    #+#             */
/*   Updated: 2025/02/25 18:03:38 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Same behaviour as ft_lstnew but in case of error at allocating memory for the node it frees the content
t_list	*ft_lstnew_s(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
	{
		free (content);
		return (NULL);
	}
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
