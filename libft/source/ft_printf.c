/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 13:38:12 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/02 05:36:24 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	toggle_specifier(const char specifier, va_list *ap)
{
	if (specifier == 'c')
		return (printchar(va_arg(*ap, int)));
	else if (specifier == 's')
		return (printstr(va_arg(*ap, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (printnbr(va_arg(*ap, int)));
	else if (specifier == 'u')
		return (printnbr_ui(va_arg(*ap, unsigned int)));
	else if (specifier == 'p')
		return (printaddress((uintptr_t)va_arg(*ap, void *)));
	else if (specifier == 'x')
		return (printx(va_arg(*ap, unsigned int), "0123456789abcdef"));
	else if (specifier == 'X')
		return (printx(va_arg(*ap, unsigned int), "0123456789ABCDEF"));
	else if (specifier == '%')
		return (printchar('%'));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		printed_byte;

	va_start(ap, format);
	printed_byte = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				break ;
			printed_byte += toggle_specifier(*format, &ap);
		}
		else
			printed_byte += printchar(*format);
		format++;
	}
	va_end(ap);
	return (printed_byte);
}
