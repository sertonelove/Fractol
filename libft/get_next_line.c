/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpataki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:53:49 by cpataki           #+#    #+#             */
/*   Updated: 2020/02/02 17:17:15 by cpataki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*check_rest(char *rest, char **pointer_n)
{
	char			*str;

	if ((*pointer_n = ft_strchr(rest, '\n')))
	{
		str = ft_strsub(rest, 0, *pointer_n - rest);
		ft_strcpy(rest, ++(*pointer_n));
	}
	else
	{
		str = ft_strnew(ft_strlen(rest) + 1);
		ft_strcat(str, rest);
		ft_strclr(rest);
	}
	return (str);
}

int		get_line(const int fd, char **line, char *rest)
{
	char			buf[BUFF_SIZE + 1];
	int				read_bytes;
	char			*pointer_n;
	char			*tmp;

	pointer_n = NULL;
	read_bytes = 1;
	*line = check_rest(rest, &pointer_n);
	while (!pointer_n && (read_bytes = read(fd, buf, BUFF_SIZE)))
	{
		buf[read_bytes] = '\0';
		if ((pointer_n = ft_strchr(buf, '\n')))
		{
			ft_strcpy(rest, ++pointer_n);
			ft_strclr(--pointer_n);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buf)) || read_bytes < 0)
			return (GNL_ERROR);
		ft_strdel(&tmp);
	}
	return ((read_bytes || ft_strlen(*line) || ft_strlen(rest))
		? GNL_OK : GNL_FINISH);
}

t_gnl	*new_list(const int fd)
{
	t_gnl			*new;

	if (!(new = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	new->fd = fd;
	new->rest = ft_strnew(BUFF_SIZE);
	new->next = NULL;
	return (new);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*head;
	t_gnl			*tmp;

	if (fd < 0 || !line)
		return (GNL_ERROR);
	if (!head)
		head = new_list(fd);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = new_list(fd);
		tmp = tmp->next;
	}
	return (get_line(tmp->fd, line, tmp->rest));
}
