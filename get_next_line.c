/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 23:22:24 by lmarques          #+#    #+#             */
/*   Updated: 2016/10/03 22:23:37 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_realloc(char *str, int size)
{
	int		count;
	char	*newstr;

	count = 0;
	if (!str)
		return (NULL);
	newstr = (char *)malloc(sizeof(*newstr) * (ft_strlen(str) + size));
	while (count < (ft_strlen(str) + size) && str[count])
	{
		//ft_putnbr(ft_strlen(str) + size);
		//ft_putchar('\n');
		newstr[count] = str[count];
		//ft_putendl(newstr);
		count++;
	}
	newstr[count] = '\0';
	free(str);
	return (newstr);
}

int		ft_parse_buffer(char **str, char **line)
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

int		get_next_line(int const fd, char **line)
{
	int		ret;
	char	*buffer;

	ft_strclr(*line);
	buffer = NULL;
	buffer = (char *)malloc(sizeof(*buffer) * BUFF_SIZE + 1);
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		write(1, "yolo\n", 5);
		buffer[ret] = '\0';
		if (ft_parse_buffer(&buffer, line))
			break ;
		*line = ft_realloc(*line, ft_strlen(buffer));
		*line = ft_strcat(*line, buffer);
	}
	free(buffer);
	return (0);
}

int		main(int argc, char *argv[])
{
	int		fd;
	char	*str;

	str = (char *)malloc(sizeof(*str) * BUFF_SIZE + 1);
	if (argc != 2)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &str);
	close(fd);
	ft_putstr(str);
	//free(str);
	return (0);
}
