/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strindexof.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- <jquinde-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:13:51 by jquinde-          #+#    #+#             */
/*   Updated: 2025/10/25 10:16:27 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_strindexof(char *str, int ch)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char) ch)
			return (i);
		i++;
	}
	if (ch == '\0')
		return (i);
	return (-1);
}
