/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strendswith.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:22:26 by jquinde-          #+#    #+#             */
/*   Updated: 2025/02/18 14:22:26 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strendswith(char *str, const char *suffix)
{
	char *start;

	start = NULL;
	while (*str)
	{
		if (*str == *suffix)
			start = str;
		str++;
	}
	if (start == NULL)
		return (0);
	while (*start)
	{
		if (*start != *suffix)
			return (0);
		start++;
		suffix++;
	}
	if (*start == '\0' && *suffix == '\0')
		return (1);
	return (0);
}
