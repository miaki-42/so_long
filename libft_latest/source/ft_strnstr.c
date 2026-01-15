/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 19:29:27 by komatsuk          #+#    #+#             */
/*   Updated: 2025/10/22 20:32:45 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	len_lit;
	size_t	i;

	len_lit = ft_strlen(little);
	if (len_lit == 0)
		return ((char *)big);
	i = 0;
	while (i < len && big[i])
	{
		if (ft_strncmp(&big[i], little, len_lit) == 0 && i + len_lit <= len)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
