/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susui <susui@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 17:12:18 by susui             #+#    #+#             */
/*   Updated: 2022/07/22 16:42:01 by susui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_discriminator(va_list *args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += putchar_int((char)va_arg(*args, int));
	else if (format == 's')
		len += putstr_int((char *)va_arg(*args, char *));
	else if (format == 'd' || format == 'i')
		len += putnmb_int((int)va_arg(*args, int));
	else if (format == 'p')
		len += put_ptr((uintptr_t)va_arg(*args, uintptr_t));
	else if (format == 'u')
		len += putui_int((unsigned int)va_arg(*args, unsigned int));
	else if (format == 'x' || format == 'X')
		len += puthex_int((unsigned int)va_arg(*args, unsigned int), format);
	else if (format == '%')
		len += write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_discriminator(&args, str[i + 1]);
			i++;
		}
		else
			len += putchar_int(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
