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
char	*assert_emptytext(t_list *empty_text);

char    *ft_readtext(int fd)
{
	t_list  *raw_text;
	size_t  size_lst;
	size_t  size_lastread; 
	char    *buffer;

	raw_text = NULL;
	ft_raw_rreadtext(fd, &raw_text);
	if (raw_text == NULL)
		return (NULL);
	if (raw_text->content == NULL)
		return (assert_emptytext(raw_text));
	size_lst = ft_lstsize(raw_text); 
	size_lastread = ft_strlen(raw_text->content);
	buffer = malloc((size_lst - 1) * BUFFER_SIZE + size_lastread + 1);
	if (buffer == NULL)
	{
		ft_lstclear(&raw_text, free);
        write(1, "Error\nAlocacion de memoria fallida\n", 36);
		return (NULL);
	}
	buffer[(size_lst - 1) * BUFFER_SIZE + size_lastread] = '\0';
	ft_rlist_to_str(raw_text, buffer + (size_lst - 1) * BUFFER_SIZE);
	ft_lstclear(&raw_text, free);
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

char	*assert_emptytext(t_list *empty_text)
 {
	char	*buffer;

	free (empty_text);
	buffer = ft_strdup("");
	if (buffer == NULL)
		write(1, "Error\nAlocacion de memoria fallida\n", 36);
	return (buffer);
 }
