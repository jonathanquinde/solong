/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readlines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- <jquinde-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 19:24:07 by jquinde-          #+#    #+#             */
/*   Updated: 2025/10/26 19:26:06 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_readlines(int fd, t_list **head)
{
	int	status_code;
	
	status_code = ft_rreadlines(fd, head);
	if (status_code != READ_SUCCESS)
		return (status_code);
	ft_lstreverse(head);
	return (READ_SUCCESS);
}
