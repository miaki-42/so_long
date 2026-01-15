/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:18:53 by komatsuk          #+#    #+#             */
/*   Updated: 2025/10/22 13:06:43 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	min(size_t n1, size_t n2)
{
	if (n1 > n2)
		return (n2);
	return (n1);
}

static	char	*my_strndup(const char *s, size_t n)
{
	char	*str;
	size_t	len_str;

	len_str = min(ft_strlen(s), n);
	str = malloc(sizeof(char) * (len_str + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, len_str + 1);
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*begin;
	char	*end;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	begin = (char *)s1;
	end = begin;
	while (*s1)
	{
		if (!ft_strchr(set, *s1))
			end = (char *)s1;
		s1++;
	}
	str = my_strndup(begin, (size_t)(end - begin + 1));
	if (!str)
		return (NULL);
	return (str);
}
