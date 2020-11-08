/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpataki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:03:46 by cpataki           #+#    #+#             */
/*   Updated: 2019/09/05 19:59:37 by cpataki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*sdst;
	unsigned char	*ssrc;
	size_t			i;

	sdst = (unsigned char *)dst;
	ssrc = (unsigned char *)src;
	i = 0;
	if (dst == src || !n)
		return (dst);
	while (i < n)
	{
		sdst[i] = ssrc[i];
		i++;
	}
	return (dst);
}
