/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpataki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 21:42:50 by cpataki           #+#    #+#             */
/*   Updated: 2019/09/10 16:59:11 by cpataki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *mem;

	mem = NULL;
	if (size == SIZE_MAX)
		return (NULL);
	if (size)
	{
		mem = (unsigned char *)malloc(size);
		if (!mem)
			return (NULL);
		ft_bzero(mem, size);
	}
	return ((void *)mem);
}
