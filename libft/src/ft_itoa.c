/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:44:00 by jquinde-          #+#    #+#             */
/*   Updated: 2024/09/25 15:26:07 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BASE "0123456789"

int	calculate_length(int num)
{
	int	i;

	i = 1;
	while (num >= 10 || num <= -10)
	{
		num /= 10;
		i++;
	}
	return (i);
}

void	recursion(int num, char *str)
{
	char	ch;
	int		n;

	if (num >= 10 || num <= -10)
		recursion(num / 10, str - 1);
	n = num % 10;
	if (n < 0)
		n *= -1;
	ch = BASE[n];
	*str = ch;
}

char	*ft_itoa(int num)
{
	int		len_str;
	char	*str;

	len_str = calculate_length(num);
	str = malloc((num < 0) + len_str + 1);
	if (str == NULL)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		str++;
	}
	str[len_str] = 0;
	recursion(num, str + (len_str - 1));
	return (str - (num < 0));
}
