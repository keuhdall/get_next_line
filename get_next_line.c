/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 23:22:24 by lmarques          #+#    #+#             */
/*   Updated: 2016/10/04 04:04:15 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_realloc(char *str, int size)
{
	int		count;
	char	*newstr;

	count = 0;
	if (!str)
		return (NULL);
	newstr = (char *)malloc(sizeof(*newstr) * (ft_strlen(str) + size + 1));
	if (!newstr)
		return (NULL);
	while (count < (ft_strlen(str) + size) && str[count])
	{
		newstr[count] = str[count];
		count++;
	}
	newstr[count] = '\0';
	free(str);
	return (newstr);
}

int			ft_parse_buffer(char **str, char **line)
{
	int	count;

	count = 0;
	while ((*str)[count])
	{
		if ((*str)[count] == '\n')
		{
			*str = ft_realloc(*str, (ft_strlen(*str) - count) * -1);
			*line = ft_realloc(*line, ft_strlen(*str));
			*line = ft_strcat(*line, *str);
			return (1);
		}
		count++;
	}
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	int		ret;
	char	*buffer;

	ft_strclr(*line);
	buffer = (char *)malloc(sizeof(*buffer) * BUFF_SIZE + 1);
	if (!buffer)
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buffer[ret] = '\0';
		if (ft_parse_buffer(&buffer, line))
			break ;
		*line = ft_realloc(*line, ft_strlen(buffer));
		*line = ft_strcat(*line, buffer);
		if (ret != BUFF_SIZE)
			return (1);
	}
	if (ret == 0 || ret != BUFF_SIZE)
		return (1);
	free(buffer);
	return (0);
}
