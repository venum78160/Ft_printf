/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 22:53:41 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/10/31 14:54:33 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_display_c(va_list args, int n)
{
	char	vl;

	vl = (char)va_arg(args, int);
	ft_putchar_fd(vl, n);
	return (1);
}
