/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: susui <susui@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 09:37:10 by susui             #+#    #+#             */
/*   Updated: 2022/05/23 15:14:24 by susui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <inttypes.h>

int		ft_printf(const char *format, ...);
int		putchar_int(int	c);
int		putstr_int(char	*str);
int		putnmb_int(int n);
int		putui_int(unsigned int num);
int		puthex_int(unsigned int num, const char format);
int		put_ptr(uintptr_t ptr);

#endif
