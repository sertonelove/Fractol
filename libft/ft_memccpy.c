/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpataki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:17:49 by cpataki           #+#    #+#             */
/*   Updated: 2019/09/09 18:01:28 by cpataki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str2;

	i = 0;
	str = (unsigned char *)src;
	str2 = (unsigned char *)dst;
	while (i < n)
	{
		str2[i] = str[i];
		if (str2[i] == (unsigned char)c)
			return (&str2[i + 1]);
		i++;
	}
	return (NULL);
}
