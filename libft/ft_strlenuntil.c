/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenuntil.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- <jquinde-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 09:47:26 by jquinde-          #+#    #+#             */
/*   Updated: 2025/10/25 10:05:51 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_strlenuntil(char *str, int ch)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		if (str[len] == (unsigned char) ch)
			return (len);
		len++;
	}
	return (-1);
}
