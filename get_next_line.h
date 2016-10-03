/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 23:38:03 by lmarques          #+#    #+#             */
/*   Updated: 2016/10/03 18:54:48 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

# include "../libft/libft.h"
# include <fcntl.h>

char	*ft_realloc(char *str, int size);
int		ft_parse_buffer(char **str, char **line);
int		ft_get_next_line(int const fd, char **line);

#endif
