/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 20:16:42 by lmarques          #+#    #+#             */
/*   Updated: 2016/09/20 14:47:12 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	int	ft_nchar(const char *s)
{
	int	count;

	count = 0;
	while (s[count] && (s[count] == ' ' ||
			s[count] == '\n' || s[count] == '\t'))
		count++;
	return (count);
}

static	int	ft_rnchar(const char *s)
{
	int	count;

	count = ft_strlen(s) - 1;
	while (s[count] && (s[count] == ' ' ||
			s[count] == '\n' || s[count] == '\t'))
		count--;
	return (count + 1);
}

char		*ft_strtrim(char const *s)
{
	int		count_s;
	int		count_str;
	char	*str;

	if (!s)
		return (NULL);
	count_s = ft_nchar(s);
	count_str = 0;
	str = NULL;
	str = (char *)malloc(sizeof(char) * (ft_rnchar(s) + ft_nchar(s)) + 1);
	if (str)
	{
		while (count_s < (ft_rnchar(s)))
		{
			str[count_str] = s[count_s];
			count_s++;
			count_str++;
		}
		str[count_str] = '\0';
	}
	return (str);
}
