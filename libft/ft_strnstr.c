/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 22:59:18 by lmarques          #+#    #+#             */
/*   Updated: 2016/09/20 14:46:44 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	count;
	size_t	count2;

	count = 0;
	if (big[count] == '\0')
		return ((char *)&big[count]);
	if (!little)
		return ((char *)big);
	if (len < (size_t)ft_strlen(little))
		return (NULL);
	while (big[count] && count < len)
	{
		count2 = 0;
		while (little[count2] && big[count + count2] &&
				big[count + count2] == little[count2])
			count2++;
		if (little[count2] == '\0' || count2 == len)
			return ((char *)&big[count]);
		count++;
	}
	return (NULL);
}
