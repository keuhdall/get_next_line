/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 22:47:16 by lmarques          #+#    #+#             */
/*   Updated: 2016/09/20 14:45:06 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_pchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int nb, int fd)
{
	long int	long_nb;

	long_nb = nb;
	if (long_nb < 0)
	{
		long_nb = -long_nb;
		ft_pchar_fd('-', fd);
	}
	if (long_nb > 9)
		ft_putnbr_fd(long_nb / 10, 1);
	ft_pchar_fd(long_nb % 10 + '0', fd);
}
