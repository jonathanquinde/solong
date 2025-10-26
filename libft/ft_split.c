/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:49:11 by jquinde-          #+#    #+#             */
/*   Updated: 2024/10/04 17:22:01 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(const char *str, char sep)
{
	int	i;

	i = 0;
	while (*str)
	{
		while (*str == sep)
			str++;
		if (!*str)
			return (i);
		while (*str && *str != sep)
			str++;
		i++;
	}
	return (i);
}

void	ft_arrstrclear(char ***ptr_arr, size_t size)
{
	char	**arr;
	size_t	i;

	arr = *ptr_arr;
	i = 0;
	while (i < size)
	{
		free (arr[i]);
		i++;
	}
	free (arr);
	*ptr_arr = NULL;
}

char	*allocate_copy_word(const char **ptr_str, char sep)
{
	int			i;
	int			j;
	char		*word;
	const char	*str;

	str = *ptr_str;
	while (*str == sep)
		str++;
	j = 0;
	while (str[j] && str[j] != sep)
		j++;
	word = malloc(j + 1);
	if (word == NULL)
		return (0);
	i = 0;
	while (str[i] && str[i] != sep)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	*ptr_str = str + i;
	return (word);
}

char	**ft_split(const char *str, char sep)
{
	int		num_words;
	int		i;
	char	*new_word;
	char	**arr_str;

	num_words = count_words(str, sep);
	arr_str = malloc(sizeof(char *) * (num_words + 1));
	if (arr_str == NULL)
		return (NULL);
	i = 0;
	while (i < num_words)
	{
		new_word = allocate_copy_word(&str, sep);
		if (new_word == NULL)
		{
			ft_arrstrclear(&arr_str, i);
			return (NULL);
		}
		arr_str[i] = new_word;
		i++;
	}
	arr_str[i] = NULL;
	return (arr_str);
}
