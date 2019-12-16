/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 14:23:19 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/15 14:29:52 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

void	ft_error(char *str, t_scene *scene)
{
	write(1, str, ft_strlen(str));
	ft_free(scene);
	exit (0);
}