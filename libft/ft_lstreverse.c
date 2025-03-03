/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:24:26 by jquinde-          #+#    #+#             */
/*   Updated: 2025/03/03 20:24:26 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstreverse(t_list **lst)
{
	t_list	*left;
	t_list	*i;
	t_list	*right;

	left = NULL;
	i = *lst;
	while (i != NULL)
	{
		right = i->next;
		i->next = left;
		left = i;
		i = right;
	}
	*lst = left;
}
