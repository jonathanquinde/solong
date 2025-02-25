/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:49:34 by jquinde-          #+#    #+#             */
/*   Updated: 2025/02/25 13:49:34 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef MATRIX_H
# define MATRIX_H
typedef struct s_matrix
{
	char	**matrix;
	size_t	width;
	size_t	height;
}					t_matrix;

void		matrix_print(t_matrix matrix);
t_matrix	matrix_new(size_t height, size_t width);
#endif