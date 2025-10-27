/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrstrclean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- <jquinde-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:23:19 by jquinde-          #+#    #+#             */
/*   Updated: 2025/10/24 21:37:53 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrstrclean(char ***arr_str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free ((*arr_str)[i]);
		i++;
	}
	free (*arr_str);
	*arr_str = NULL;
}
