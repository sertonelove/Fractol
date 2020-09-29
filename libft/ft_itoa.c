/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpataki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:58:22 by cpataki           #+#    #+#             */
/*   Updated: 2019/09/12 23:19:26 by cpataki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_dcount(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	if (n < 10)
		i++;
	return (i);
}

static void		ft_rec(char *str, int n, int *i)
{
	unsigned int	m;

	m = n;
	if (n < 0)
	{
		str[*i] = '-';
		*i = (*i) + 1;
		m = -n;
	}
	if (m > 9)
	{
		ft_rec(str, m / 10, i);
		ft_rec(str, m % 10, i);
	}
	if (m < 10)
	{
		str[*i] = m + '0';
		*i = (*i) + 1;
	}
}

char			*ft_itoa(int n)
{
	char	*str;
	int		a;
	int		*i;

	i = &a;
	a = 0;
	str = (char *)malloc(sizeof(char) * (ft_dcount(n) + 1));
	if (str)
	{
		ft_rec(str, n, i);
		str[a] = '\0';
	}
	return (str);
}
