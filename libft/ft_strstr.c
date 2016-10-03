/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 05:11:34 by lmarques          #+#    #+#             */
/*   Updated: 2016/09/09 04:13:29 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	count;
	int	count2;

	count = 0;
	if (big[count] == '\0')
		return ((char *)&big[count]);
	if (!little)
		return ((char *)big);
	while (big[count])
	{
		count2 = 0;
		while (big[count + count2] && little[count2] &&
			(big[count + count2] == little[count2]))
			count2++;
		if (little[count2] == '\0')
			return ((char *)&big[count]);
		count++;
	}
	return (NULL);
}
