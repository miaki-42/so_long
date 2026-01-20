/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:54:48 by komatsuk          #+#    #+#             */
/*   Updated: 2025/10/19 21:00:13 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_uc;
	unsigned char	chr;
	size_t			i;

	s_uc = (unsigned char *)s;
	chr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s_uc[i] == chr)
			return ((void *)&s_uc[i]);
		i++;
	}
	return (NULL);
}
