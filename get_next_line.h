/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 23:38:03 by lmarques          #+#    #+#             */
/*   Updated: 2016/10/28 02:52:32 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

# include "./libft/libft.h"
# include <fcntl.h>

int		ft_parse_buffer(char **str, char **line, char **tmp);
char	*ft_set_tmp(char *tmp, char *buffer, int count);
char	*ft_set_line(char *line, char *buffer);
int		get_next_line(int const fd, char **line);

#endif
