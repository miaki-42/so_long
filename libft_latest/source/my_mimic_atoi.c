/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mimic_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:45:48 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/04 18:52:22 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	get_value(const char *nptr, int *n, int sign)
{
	int	digit;

	while (*nptr)
	{
		if (!ft_isdigit(*nptr))
			return (false);
		digit = *nptr - '0';
		if (sign == 1)
		{
			if ((INT_MAX - digit) / 10 < *n)
				return (false);
		}
		else if (sign == -1)
		{
			if (-(INT_MIN / 10) < *n)
				return (false);
			else if (-(INT_MIN / 10) == *n && digit > -(INT_MIN % 10))
				return (false);
		}
		*n = *n * 10 + (*nptr - '0');
		nptr++;
	}
	*n *= sign;
	return (true);
}

bool	my_mimic_atoi(const char *nptr, int *n)
{
	int	sign;

	*n = 0;
	while (my_isspace(*nptr))
		nptr++;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	if (!*nptr || !get_value(nptr, n, sign))
		return (false);
	return (true);
}
