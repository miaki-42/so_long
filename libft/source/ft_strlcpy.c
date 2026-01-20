/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 10:54:42 by komatsuk          #+#    #+#             */
/*   Updated: 2025/10/20 11:37:13 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;

	srclen = 0;
	if (size > 0)
	{
		while (srclen < size - 1 && src[srclen])
		{
			dst[srclen] = src[srclen];
			srclen++;
		}
		dst[srclen] = '\0';
	}
	while (src[srclen])
		srclen++;
	return (srclen);
}
