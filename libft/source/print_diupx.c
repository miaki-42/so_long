/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_diupx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:10:36 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/02 05:37:57 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printnbr(int n)
{
	int	written_byte;

	if (n == INT_MIN)
		return (write(1, "-2147483648", 11));
	else
	{
		written_byte = 0;
		if (n < 0)
		{
			written_byte += printchar('-');
			n = -n;
		}
		if (n / 10 != 0)
			written_byte += printnbr(n / 10);
		return (written_byte + printchar('0' + n % 10));
	}
}

int	printnbr_ui(unsigned int n)
{
	int	written_byte;

	written_byte = 0;
	if (n / 10 != 0)
		written_byte += printnbr_ui(n / 10);
	return (written_byte + printchar('0' + n % 10));
}

static int	rec(uintptr_t p, char *basestr)
{
	int	written_byte;

	written_byte = 0;
	if (p / 16 != 0)
		written_byte += rec(p / 16, basestr);
	return (written_byte + printchar(basestr[p % 16]));
}

int	printaddress(uintptr_t p)
{
	if (!p)
		return (printstr("(nil)"));
	return (printstr("0x") + rec(p, "0123456789abcdef"));
}

int	printx(unsigned int n, char *basestr)
{
	int	written_byte;

	written_byte = 0;
	if (n / 16 != 0)
		written_byte += printx(n / 16, basestr);
	return (written_byte + printchar(basestr[n % 16]));
}
