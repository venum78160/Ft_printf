/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 19:25:06 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/11/03 15:16:45 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_display(char type, va_list args)
{
	if (type == 'c')
		return (ft_display_c(args, 1));
	else if (type == 's')
		return (ft_display_s(args, 1));
	else if (type == 'p')
		return (ft_display_p(args));
	else if (type == 'd' || type == 'i')
		return (ft_display_int(args, 1));
	else if (type == 'u')
		return (ft_display_u(args, 1));
	else if (type == 'x')
		return (ft_display_x(args));
	else if (type == 'X')
		return (ft_display_xmaj(args));
	else
		return (ft_display_pourc('%', 1));
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		size;
	char	type;

	size = 0;
	va_start(args, string);
	while (*string)
	{
		if (*string == '%' && ft_strchr("cspdiuxX%",*(string + 1)))
		{
			type = *(string + 1);
			size += ft_display(type, args);
			string += 2;
		}
		else
		{
			ft_putchar_fd(*string, 1);
			size++;
			string++;
		}
	}
	va_end(args);
	return (size);
}
