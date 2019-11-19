/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:32:26 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/19 13:31:06 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>
#include <unistd.h>

int main(int ac, char **av)
{
    t_window  data;
	// t_point	start;
	// t_point	end;
	// t_sphere sphere;

	// start.x = 200.580;
	// start.y = 200.580;
	// end.x	= 945.8;
	// end.y 	= 351;
	// sphere.x = 1000.0;
	// sphere.y = 200.0;
	// sphere.z = 500.0;
	// sphere.radius = 200.0;
	// sphere.colour = 0xff0000;
	// if (ac == 2)
	// 	parse_file(&data, av[1]);
	// else
	// 	ft_error(1);
	(void)ac;
	(void)av;
    if ((data.mlx_ptr = mlx_init()) == NULL)
        return (EXIT_FAILURE);
	data.width = 1280.0;
	data.heigth = 1024.0;
    if ((data.mlx_win = mlx_new_window(data.mlx_ptr, data.width, data.heigth, "miniRT")) == NULL)
        return (EXIT_FAILURE);
	mlx_loop(data.mlx_ptr);
    return (EXIT_SUCCESS);
} 
