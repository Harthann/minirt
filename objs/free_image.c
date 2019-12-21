/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 18:49:07 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/15 12:55:29 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_image(t_img *img)
{
	if (img)
	{
		if (img->next && !img->end)
			free_image(img->next);
		free(img->image);
		free(img->ptr);
		free(img);
	}
}
