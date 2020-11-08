/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duobrot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpataki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:42:53 by cpataki           #+#    #+#             */
/*   Updated: 2020/10/11 13:10:40 by cpataki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	duobrot_init(t_fractol *data)
{
	data->it_max = 50;
	data->zoom = 200;
	data->x1 = -1.8;
	data->y1 = -1.7;
	data->color = 265;
}

void	duobrot_calc(t_fractol *data)
{
	data->c_r = data->x / data->zoom + data->x1;
	data->c_i = data->y / data->zoom + data->y1;
	data->z_r = 0;
	data->z_i = 0;
	data->it = 0;
	while (data->z_r * data->z_r + data->z_i *
	data->z_i < 8 && data->it < data->it_max)
	{
		data->tmp = data->z_r;
		data->z_r = (data->z_r * data->z_r -
			(3.0 * data->z_i * data->z_i)) * data->z_r + data->c_r;
		data->z_i = ((3.0 * data->tmp * data->tmp) - data->z_i * data->z_i) *
			data->z_i + data->c_i;
		data->it++;
	}
	if (data->it == data->it_max)
		put_pxl_to_img(data, data->x, data->y, 0x000000);
	else
		put_pxl_to_img(data, data->x, data->y, (data->color * data->it));
}

void	*duobrot(void *tab)
{
	t_fractol	*data;
	int			tmp;

	data = (t_fractol *)tab;
	data->x = 0;
	tmp = data->y;
	while (data->x < WIDTH)
	{
		data->y = tmp;
		while (data->y < data->y_max)
		{
			duobrot_calc(data);
			data->y++;
		}
		data->x++;
	}
	return (tab);
}

void	duobrot_pthread(t_fractol *data)
{
	t_fractol	tab[THREAD_NUMBER];
	pthread_t	t[THREAD_NUMBER];
	int			i;

	i = 0;
	while (i < THREAD_NUMBER)
	{
		ft_memcpy((void*)&tab[i], (void*)data, sizeof(t_fractol));
		tab[i].y = THREAD_WIDTH * i;
		tab[i].y_max = THREAD_WIDTH * (i + 1);
		pthread_create(&t[i], NULL, duobrot, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
