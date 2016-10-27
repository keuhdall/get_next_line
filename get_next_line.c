/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 23:22:24 by lmarques          #+#    #+#             */
/*   Updated: 2016/10/27 17:47:46 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_set_tmp(char *tmp, char *buffer, int count)
{
	if (!buffer)
		return (NULL);
	if (tmp)
	{
		tmp = (char *)malloc(sizeof(char) *
			(ft_strlen(tmp) + ft_strlen(buffer) - count) + 1);
		if (tmp)
			tmp = ft_strcpy(tmp, buffer + count + 1);
	}
	else
	{
		tmp = (char *)malloc(sizeof(char) *
			(ft_strlen(buffer) - count) + 1);
		if (tmp)
			tmp = ft_strcpy(tmp, buffer + count + 1);
		else
			tmp = NULL;
	}
	return (tmp);
}

char	*ft_set_line(char *line, char *buffer)
{
	if (!line)
	{
		line = (char *)malloc(sizeof(char) * ft_strlen(buffer) + 1);
		if (!line)
			return (NULL);
		ft_bzero(line, ft_strlen(buffer) + 1);
	}
	else
		line = ft_realloc(line, ft_strlen(buffer));
	line = ft_strcat(line, buffer);
	return (line);
}

int		ft_parse_buffer(char **buffer, char **line, char **tmp)
{
	int	count;

	count = 0;
	while ((*buffer)[count])
	{
		if ((*buffer)[count] == '\n')
		{
			if (count < ft_strlen(*buffer))
				*tmp = ft_set_tmp(*tmp, *buffer, count);
			*buffer = ft_realloc(*buffer, (ft_strlen(*buffer) - count) * -1);
			*line = ft_set_line(*line, *buffer);
			return (1);
		}
		count++;
	}
	if (*tmp)
		*tmp = (char *)malloc(sizeof(char) * ft_strlen(*tmp) + BUFF_SIZE + 1);
	else
		*tmp = (char *)malloc(sizeof(char) * BUFF_SIZE);
	*tmp = ft_strcpy(*tmp, *buffer);
	return (0);
}

char	*ft_add_term_char(char *buffer, int ret)
{
	if (!buffer)
		return (NULL);
	if (ret != BUFF_SIZE && ret != 0 && buffer[ret - 1] != '\n')
	{
		buffer = ft_realloc(buffer, 1);
		buffer[ret] = '\n';
		buffer[ret + 1] = '\0';
	}
	else
		buffer[ret] = '\0';
	return (buffer);
}

int		get_next_line(int const fd, char **line)
{
	int			ret;
	char		*buffer;
	static char	*tmp = NULL;

	buffer = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (!buffer || fd < 0 || !line)
		return (-1);
	*line = NULL;
	while (1)
	{
		ret = read(fd, buffer, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		buffer = ft_add_term_char(buffer, ret);
		if (tmp && ft_strlen(tmp) != 0)
		{
			tmp = ft_realloc(tmp, ft_strlen(buffer));
			buffer = ft_strcat(tmp, buffer);
		}
		if (ft_parse_buffer(&buffer, line, &tmp))
			break ;
		if (ft_strlen(tmp) == 0)
			return (0);
	}
	return (1);
}
