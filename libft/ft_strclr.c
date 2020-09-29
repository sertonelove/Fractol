/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpataki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 22:52:36 by cpataki           #+#    #+#             */
/*   Updated: 2019/09/09 13:22:54 by cpataki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_strclr(char *s)
{
	size_t	len;

	if (s)
	{
		len = ft_strlen(s);
		ft_memset((char *)s, '\0', len);
	}
	else
		return ;
}
