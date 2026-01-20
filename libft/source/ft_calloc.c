/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 20:26:57 by komatsuk          #+#    #+#             */
/*   Updated: 2025/10/20 13:12:10 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	mult_size;

	if (nmemb != 0 && SIZE_MAX / nmemb < size)
		return (NULL);
	mult_size = nmemb * size;
	p = malloc(mult_size);
	if (!p)
		return (NULL);
	ft_bzero(p, mult_size);
	return (p);
}
