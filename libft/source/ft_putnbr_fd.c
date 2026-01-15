/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 21:24:40 by komatsuk          #+#    #+#             */
/*   Updated: 2025/10/22 19:59:07 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rec(int n, int fd)
{
	if (n / 10 != 0)
		rec(n / 10, fd);
	ft_putchar_fd('0' - n % 10, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd >= 0)
	{
		if (n >= 0)
			n = -n;
		else
			ft_putchar_fd('-', fd);
		rec(n, fd);
	}
}
