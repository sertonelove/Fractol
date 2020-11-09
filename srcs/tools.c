/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpataki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 17:06:07 by cpataki           #+#    #+#             */
/*   Updated: 2020/09/14 15:32:36 by cpataki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_close(void)
{
	exit(1);
	return (0);
}

void	put_pxl_to_img(t_fractol *data, int x, int y, int color)
{
	if (data->x < WIDTH && data->y < WIDTH)
	{
		color = mlx_get_color_value(data->mlx, color);
		ft_memcpy(data->img_ptr + 4 * WIDTH * y + x * 4,
				&color, sizeof(int));
	}
}

void	put_text(t_fractol *data)
{
	char	*text;

	text = "next : 6; previous : 4; change color : 1, 2, 3, +; return : space";
	mlx_string_put(data->mlx, data->win, 10, 10, 0xFFFFFF, text);
}
