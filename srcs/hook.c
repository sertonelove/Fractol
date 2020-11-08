/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpataki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 20:00:26 by cpataki           #+#    #+#             */
/*   Updated: 2020/09/11 11:46:58 by cpataki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook2(int keycode, t_fractol *data)
{
	if (keycode == 19)
		data->color = 1800;
	else if (keycode == 20)
		data->color = 265;
	else if (keycode == 24)
		data->color += 50;
	else if (keycode == 35)
		data->julia_mouse = !data->julia_mouse;
	else if (keycode == 34)
		data->show_text = !data->show_text;
	else if (keycode == 21 && (data->fract - 1 >= 0))
		data->fract--;
	else if (keycode == 22 && (data->fract + 1 <= 4))
		data->fract++;
	return (0);
}

int		key_hook(int keycode, t_fractol *data)
{
	if (keycode == 53)
		exit(1);
	else if (keycode == 69)
		data->it_max += 50;
	else if (keycode == 78)
		data->it_max -= 50;
	else if (keycode == 123)
		data->x1 -= 30 / data->zoom;
	else if (keycode == 124)
		data->x1 += 30 / data->zoom;
	else if (keycode == 125)
		data->y1 += 30 / data->zoom;
	else if (keycode == 126)
		data->y1 -= 30 / data->zoom;
	else if (keycode == 49)
		fract_init(data);
	else if (keycode == 18)
		data->color = 3677216;
	key_hook2(keycode, data);
	fract_calc(data);
	return (0);
}

void	ft_zoom(int x, int y, t_fractol *data)
{
	data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom * 1.3));
	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom * 1.3));
	data->zoom *= 1.3;
	data->it_max++;
}

void	ft_dezoom(int x, int y, t_fractol *data)
{
	data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom / 1.3));
	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom / 1.3));
	data->zoom /= 1.3;
	data->it_max--;
}

int		mouse_hook(int mousecode, int x, int y, t_fractol *data)
{
	if (mousecode == 4 || mousecode == 1)
		ft_zoom(x, y, data);
	else if (mousecode == 5 || mousecode == 2)
		ft_dezoom(x, y, data);
	fract_calc(data);
	return (0);
}
