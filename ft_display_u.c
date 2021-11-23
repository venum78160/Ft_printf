/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 14:51:41 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/10/31 11:06:00 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_fd_u(unsigned int n, int fd)
{
	if (n > 9)
		ft_putnbr_fd_u(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

int	ft_display_u(va_list args, int fd)
{
	unsigned int	vl;
	int				size;

	size = 0;
	vl = (unsigned int)va_arg(args, unsigned int);
	ft_putnbr_fd_u(vl, fd);
	if (vl == 0)
		return (1);
	while (vl > 0)
	{
		vl = vl / 10;
		size++;
	}
	return (size);
}
