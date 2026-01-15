/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:52:02 by komatsuk          #+#    #+#             */
/*   Updated: 2025/10/22 13:03:27 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digit(int n)
{
	size_t	cnt;

	cnt = 1;
	if (n < 0)
		cnt++;
	else
		n = -n;
	while (n / 10 != 0)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}

void	rec(char *str, int n, size_t i)
{
	if (n > 0)
		n = -n;
	if (n / 10 != 0)
		rec(str, n / 10, i - 1);
	str[i] = '0' - n % 10;
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	strsize;

	strsize = count_digit(n);
	str = malloc(strsize + 1);
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	rec(str, n, strsize - 1);
	str[strsize] = '\0';
	return (str);
}
