/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readtext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:43:11 by jquinde-          #+#    #+#             */
/*   Updated: 2025/10/26 19:26:07 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rlist_to_str(t_list *node, char *buffer)
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

int	ft_readtext(int fd, char **buffer)
{
	t_list	*raw_text;
	size_t	size_lst;
	size_t	size_lastread; 
	int		read_status;

	raw_text = NULL;
	read_status = ft_raw_rreadtext(fd, &raw_text); 
	if (read_status != READ_SUCCESS)
		return (read_status);
	size_lst = ft_lstsize(raw_text); 
	size_lastread = ft_strlen(raw_text->content);
	*buffer = malloc((size_lst - 1) * BUFFER_SIZE + size_lastread + 1);
	if (*buffer == NULL)
	{
		ft_lstclear(&raw_text, free);
		return (READ_FAIL_MALLOC);
	}
	(*buffer)[(size_lst - 1) * BUFFER_SIZE + size_lastread] = '\0';
	ft_rlist_to_str(raw_text, *buffer + (size_lst - 1) * BUFFER_SIZE);
	ft_lstclear(&raw_text, free);
	return (READ_SUCCESS);
}

