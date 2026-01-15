/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:37:44 by komatsuk          #+#    #+#             */
/*   Updated: 2025/10/20 15:35:57 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;

	if (size == 0)
		return (ft_strlen(src));
	dstlen = ft_strlen(dst);
	if (dstlen >= size)
		return (size + ft_strlen(src));
	srclen = 0;
	size -= dstlen;
	while (src[srclen] && size > 1)
	{
		dst[dstlen + srclen] = src[srclen];
		srclen++;
		size--;
	}
	dst[dstlen + srclen] = '\0';
	while (src[srclen])
		srclen++;
	return (dstlen + srclen);
}
