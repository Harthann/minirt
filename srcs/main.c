/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:32:26 by nieyraud          #+#    #+#             */
/*   Updated: 2019/11/19 18:50:12 by nieyraud         ###   ########.fr       */
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
    t_scene scene;
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
	if (ac == 2 || ac == 3)
	{
		scene = parse_file(av[1]);
	}
	// else
	// 	ft_error(1);
	(void)ac;
	(void)av;
    if ((scene.win.mlx_ptr = mlx_init()) == NULL)
        return (EXIT_FAILURE);
	printf("[%d] [%d]\n", scene.win.heigth, scene.win.width);
    if ((scene.win.mlx_win = mlx_new_window(scene.win.mlx_ptr, scene.win.width, scene.win.heigth, "miniRT")) == NULL)
        return (EXIT_FAILURE);
	mlx_loop(scene.win.mlx_ptr);
    return (EXIT_SUCCESS);
} 
