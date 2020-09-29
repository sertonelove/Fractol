/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpataki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:57:29 by cpataki           #+#    #+#             */
/*   Updated: 2019/09/14 16:19:12 by cpataki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*ft_clear(char **str)
{
	int	j;

	j = 0;
	while (str[j])
		free(str[j++]);
	free(str[j]);
	free(str);
	return (NULL);
}

static int		ft_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int		ft_count_words(char const *s, char c)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s || !c)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1))))
		return (NULL);
	while (j < ft_count_words(s, c))
	{
		while (s[i] == c)
			i++;
		if (!(str[j] = (char *)malloc(sizeof(char) * (ft_len(s + i, c) + 1))))
			return (ft_clear(str));
		str[j] = ft_strncpy(str[j], s + i, ft_len(s + i, c));
		str[j][ft_len(s + i, c)] = '\0';
		while (s[i] && s[i] != c)
			i++;
		j++;
	}
	str[j] = NULL;
	return (str);
}
