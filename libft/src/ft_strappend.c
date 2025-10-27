/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- <jquinde-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:18:52 by jquinde-          #+#    #+#             */
/*   Updated: 2025/10/25 10:26:02 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strappend(char **str, char *value)
{
	size_t	len_new;
	size_t	len_str;
	char	*new_str;

	if (value == NULL)
		return ;
	else if (*str == NULL)
	{
		*str = ft_strdup(value);
		return ;
	}
	len_str = ft_strlen(*str);
	len_new = len_str + ft_strlen(value);
	new_str = malloc(len_new + 1);
	if (new_str == NULL)
	{
		ft_strclean(str);
		return ;
	}
	ft_strcpy(new_str, *str);
	ft_strcpy(new_str + len_str, value);
	free (*str);
	*str = new_str;
}
