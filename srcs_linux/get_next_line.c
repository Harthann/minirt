/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:40:36 by nieyraud          #+#    #+#             */
/*   Updated: 2019/12/16 21:05:58 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_stock		*new_fd(int fd)
{
	t_stock *new;

	if (!(new = (t_stock*)malloc(sizeof(t_stock))))
		return (NULL);
	new->next = NULL;
	new->fd = fd;
	new->str = NULL;
	return (new);
}

static	void		ft_addfront(t_stock **alst, t_stock *new, int error)
{
	if (alst && error > 0)
	{
		if (*alst && new)
			new->next = *alst;
		*alst = new;
	}
	else
	{
		if (new && new->str)
		{
			free(new->str);
			new->str = NULL;
			free(new);
		}
	}
}

static int			reading_file(int fd, char **stock)
{
	char	*buffer;
	int		buff;

	buff = 1;
	if (ft_search(*stock, '\n') != -1)
		return (1);
	if (!(buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	*buffer = '\0';
	while (ft_search(buffer, '\n') == -1 && buff > 0)
	{
		buff = read(fd, buffer, BUFFER_SIZE);
		if (buff >= 0)
		{
			buffer[buff] = '\0';
			if (!(*stock))
				*stock = ft_substr(buffer, 0, buff);
			else
				*stock = ft_strjoin_free(*stock, buffer, 1);
		}
	}
	free(buffer);
	return (buff > 0 ? 1 : buff);
}

static int			stock_line(char **line, t_stock *stock)
{
	char	*to_free;
	int		length;
	int		error;

	if (!line)
		return (-1);
	if ((error = reading_file(stock->fd, &stock->str)) < 0)
		return (-1);
	length = ft_search(stock->str, '\n');
	length == -1 ? length = ft_strlen(stock->str) : length;
	if (!(*line = ft_substr(stock->str, 0, length)))
		return (-1);
	to_free = stock->str;
	length++;
	stock->str = ft_substr(stock->str, length, ft_strlen(stock->str) + length);
	if (to_free)
	{
		free(to_free);
		to_free = NULL;
	}
	return (error);
}

int					get_next_line(int fd, char **line)
{
	static	t_stock	*stock = NULL;
	t_stock			*actual;
	t_stock			*previous;
	int				error;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	previous = NULL;
	actual = stock;
	while (actual && actual->fd != fd)
	{
		previous = actual;
		actual = actual->next;
	}
	if (previous && actual)
		previous->next = actual->next;
	else if (actual)
		stock = actual->next;
	else
		actual = new_fd(fd);
	error = stock_line(line, actual);
	ft_addfront(&stock, actual, error);
	return (error);
}
