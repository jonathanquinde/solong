/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:39:57 by jquinde-          #+#    #+#             */
/*   Updated: 2025/02/25 16:39:57 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"

#ifndef FILE_H
# define FILE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif
void	ft_raw_rreadtext(int fd, t_list **head);
char    *ft_readtext(int fd);
t_list  *ft_rreadlines(int fd);
#endif