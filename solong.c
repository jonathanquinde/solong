/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 00:15:46 by jquinde-          #+#    #+#             */
/*   Updated: 2025/01/18 00:15:46 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int argc, char *argv[])
{
    t_list *start;

    if (argc != 2)
    {
        write(1, MSG_ERROR_Nª_PARAMS, 73);
        return (1);
    }
    start = validate_map(argv[1]);
    if (start == NULL)
        return (1);
}
