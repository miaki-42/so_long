/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 00:28:52 by komatsuk          #+#    #+#             */
/*   Updated: 2026/01/17 02:22:14 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	puterr()
{
	ft_putstr_fd("Error\n", 2);
}

int	my_strcmp(const char *s1, const char *s2)
{
	unsigned char	*ucs1;
	unsigned char	*ucs2;

	ucs1 = (unsigned char*)s1;
	ucs2 = (unsigned char*)s2;
	while (*ucs1 && *ucs1 == *ucs2)
	{
		ucs1++;
		ucs2++;
	}
	return (*ucs1 - *ucs2);
}