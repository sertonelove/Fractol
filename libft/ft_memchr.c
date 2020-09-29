/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpataki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:15:39 by cpataki           #+#    #+#             */
/*   Updated: 2019/09/07 16:54:36 by cpataki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;
	int				i;

	i = 0;
	str = (unsigned char *)s;
	ch = (unsigned char)c;
	while (n--)
	{
		if (str[i] == ch)
			return (str + i);
		i++;
	}
	return (NULL);
}
