/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:09:09 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/10/31 14:55:32 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_rev_int_tab(char *tab)
{
	int	n;
	int	tmp;
	int	size;

	size = ft_strlen(tab);
	n = 0;
	while (n < size / 2)
	{
		tmp = tab[n];
		tab[n] = tab [size - 1 - n];
		tab [size - 1 - n] = tmp;
		n++;
	}
	return (tab);
}

static int	ft_putnbr_hexadecimal(unsigned int args, char *base)
{
	char			rendu[10];
	int				i;

	i = 0;
	while (args > 0)
	{
		rendu[i++] = base[args % 16];
		args = args / 16;
	}
	rendu[i] = '\0';
	ft_putstr_fd(ft_rev_int_tab(rendu), 1);
	return (ft_strlen(rendu));
}

int	ft_display_x(va_list args)
{
	unsigned int	vl;
	int				size;

	size = 0;
	vl = (unsigned int)va_arg(args, int);
	if (vl == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	return (ft_putnbr_hexadecimal(vl, "0123456789abcdef"));
}
