/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:10:36 by komatsuk          #+#    #+#             */
/*   Updated: 2025/10/22 20:16:56 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*matched;
	char	chr;

	matched = NULL;
	chr = (char)c;
	while (*s)
	{
		if (*s == chr)
			matched = (char *)s;
		s++;
	}
	if (chr == '\0')
		return ((char *)s);
	return (matched);
}
