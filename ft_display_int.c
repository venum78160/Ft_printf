/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 10:57:09 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/10/31 10:55:59 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_display_int(va_list args, int fd)
{
	int	vl;
	int	size;

	size = 0;
	vl = (int)va_arg(args, int);
	ft_putnbr_fd(vl, fd);
	if (vl == 0)
		return (1);
	if (vl == -2147483648)
		return (11);
	if (vl < 0)
	{
		vl *= -1;
		size++;
	}
	while (vl > 0)
	{
		vl = vl / 10;
		size++;
	}
	return (size);
}
