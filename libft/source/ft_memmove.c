/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 16:34:15 by komatsuk          #+#    #+#             */
/*   Updated: 2025/10/21 17:20:25 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_uc;
	unsigned char	*src_uc;

	if (dest <= src)
		ft_memcpy(dest, src, n);
	else if (src < dest)
	{
		dest_uc = (unsigned char *)dest;
		src_uc = (unsigned char *)src;
		while (n > 0)
		{
			n--;
			dest_uc[n] = src_uc[n];
		}
	}
	return (dest);
}
