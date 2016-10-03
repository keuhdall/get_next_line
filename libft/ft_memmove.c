/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 18:15:48 by lmarques          #+#    #+#             */
/*   Updated: 2016/09/11 17:02:13 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	tmp[n];
	size_t	count;

	count = 0;
	while (count < n)
	{
		((char *)tmp)[count] = ((char *)src)[count];
		count++;
	}
	count = 0;
	while (count < n)
	{
		((char *)dst)[count] = tmp[count];
		count++;
	}
	return (dst);
}
