/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpataki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:00:33 by cpataki           #+#    #+#             */
/*   Updated: 2019/09/11 16:27:40 by cpataki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;

	i = ft_strlen(needle);
	if (i == 0)
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
			if (ft_strncmp(needle, haystack, i) == 0)
				return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
