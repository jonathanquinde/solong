/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readtext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:43:11 by jquinde-          #+#    #+#             */
/*   Updated: 2025/02/20 18:43:11 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void	ft_rlist_to_str(t_list *node, char *buffer);

char    *ft_readtext(int fd)
{
	t_list  *text;
	size_t  size_lst;
	size_t  size_lastread; 
	char    *buffer;

	text = NULL;
	ft_raw_rreadtext(fd, &text);
	if (text == NULL)
		return (NULL);
	size_lst = ft_lstsize(text); 
	size_lastread = ft_strlen(text->content);
	buffer = malloc((size_lst - 1) * BUFFER_SIZE + size_lastread + 1);
    if (buffer == NULL)
    {
        ft_lstclear(&text, free);
        return (NULL);
    }
    buffer[(size_lst - 1) * BUFFER_SIZE + size_lastread] = '\0';
	ft_rlist_to_str(text, buffer + (size_lst - 1) * BUFFER_SIZE);
	ft_lstclear(&text, free);
	return (buffer);
}

void	ft_rlist_to_str(t_list *node, char *buffer)
{
	char	*i;

	if (node == NULL)
		return ;
	i = node->content;
	while (*i)
	{
		*buffer = *i;
		i++;
		buffer++;
	}
	ft_rlist_to_str(node->next, buffer - ((i - (char *)node->content) + BUFFER_SIZE));
}
