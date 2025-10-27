/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readlines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:29:42 by jquinde-          #+#    #+#             */
/*   Updated: 2025/02/26 18:29:42 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int    text_to_lines(t_list **lines, char *text)
{
	char	*start;
	char	*end;
	t_list	*node;

	start = text;
	while (*start != '\0')
	{
		end = start + 1;
		while (*end != '\n' && *end != '\0')
			end++;
		node = ft_lstnew(malloc(end - start + 1));
		if (node == NULL || node->content == NULL)
		{
			ft_lstdelone(node, free);
			ft_lstclear(lines, free);
			return (READ_FAIL_MALLOC);
		}
		ft_memcpy(node->content, start, end - start);
		((char *) node->content)[end - start] = '\0';
		ft_lstadd_front(lines, node);
		start = end + (*end == '\n');
	}
	return (READ_SUCCESS);
}

int	ft_rreadlines(int fd, t_list **head)
{
	char    *text;
	int		read_status;

	text = NULL;
	read_status = ft_readtext(fd, &text);
	if (read_status != READ_SUCCESS)
		return (read_status);
	*head = NULL;
	read_status = text_to_lines(head, text);
	free (text);
	return (READ_SUCCESS);
}

