/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcontains_ch.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- <jquinde-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 10:04:42 by jquinde-          #+#    #+#             */
/*   Updated: 2025/10/25 10:05:37 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strcontains_ch(char	*str, int ch)
{
	while (*str)
	{
		if (*str == (unsigned char) ch)
			return (1);
		str++;
	}
	return (0);
}
