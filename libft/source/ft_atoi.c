/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:43:35 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/04 19:01:26 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	get_value(const char *nptr, long sign)
{
	long	n;
	long	digit;

	n = 0;
	while (ft_isdigit(*nptr))
	{
		digit = *nptr - '0';
		if (sign == 1)
		{
			if ((LONG_MAX - digit) / 10 < n)
				return (LONG_MAX);
		}
		else if (sign == -1)
		{
			if (-(LONG_MIN / 10) < n)
				return (LONG_MIN);
			else if (-(LONG_MIN / 10) == n && digit > -(LONG_MIN % 10))
				return (LONG_MIN);
		}
		n = n * 10 + (*nptr - '0');
		nptr++;
	}
	return (n * sign);
}

int	ft_atoi(const char *nptr)
{
	long	sign;

	while (my_isspace(*nptr))
		nptr++;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	return ((int)get_value(nptr, sign));
}
