/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:35:15 by komatsuk          #+#    #+#             */
/*   Updated: 2025/10/20 15:01:49 by komatsuk         ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		substr = ft_calloc(1, 1);
		if (!substr)
			return (NULL);
	}
	else
	{
		substr = my_strndup(&s[start], len);
		if (!substr)
			return (NULL);
	}
	return (substr);
}
