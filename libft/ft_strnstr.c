/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpataki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 22:16:29 by cpataki           #+#    #+#             */
/*   Updated: 2019/09/12 19:47:52 by cpataki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	n;
	size_t	lens2;

	if (*s2 == '\0')
		return ((char *)s1);
	n = 0;
	lens2 = ft_strlen(s2);
	while (*s1 != '\0')
	{
		if (n + lens2 > len)
			return (NULL);
		if (ft_strncmp(s1, s2, lens2) == 0)
			return ((char *)s1);
		s1++;
		n++;
	}
	return (NULL);
}
