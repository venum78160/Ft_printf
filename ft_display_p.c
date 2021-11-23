/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 08:17:15 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/10/31 14:54:51 by vl-hotel         ###   ########.fr       */
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

static int	ft_putnbr_hexadecimal(unsigned long args, char *base)
{
	char			rendu[40];
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

int	ft_display_p(va_list args)
{
	unsigned long	add;
	void			*p;
	unsigned int	size;

	p = (void *)va_arg(args, void *);
	add = (unsigned long) p;
	ft_putstr_fd("0x", 1);
	size = (ft_putnbr_hexadecimal(add, "0123456789abcdef"));
	if (add == 0)
	{
		ft_putchar_fd('0', 1);
		return (3);
	}
	return (size + 2);
}
