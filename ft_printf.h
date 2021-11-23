/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 08:57:47 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/10/31 14:56:23 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libft/libft.h"
# include <stdarg.h>

//prototype 

int	ft_display_c(va_list args, int n);
int	ft_display_int(va_list args, int fd);
int	ft_display_p(va_list args);
int	ft_display_s(va_list args, int n);
int	ft_display_u(va_list args, int fd);
int	ft_display_x(va_list args);
int	ft_display_xmaj(va_list args);
int	ft_printf(const char *string, ...);
int	ft_display_pourc(char args, int n);

#endif
