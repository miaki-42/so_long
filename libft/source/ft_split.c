/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:49:54 by komatsuk          #+#    #+#             */
/*   Updated: 2025/10/22 12:49:44 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t	cnt;
	bool	isdelim;

	cnt = 0;
	isdelim = true;
	while (*s)
	{
		if (isdelim && *s != c)
			cnt++;
		if (*s == c)
			isdelim = true;
		else
			isdelim = false;
		s++;
	}
	return (cnt);
}

static char	*my_strndup(const char *s, size_t n)
{
	char	*str;
	size_t	len_str;
	size_t	len_s;

	len_str = n;
	len_s = ft_strlen(s);
	if (len_s < n)
		len_str = len_s;
	str = malloc(sizeof(char) * (len_str + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, len_str + 1);
	return (str);
}

static void	free_all(char **strs, size_t cnt)
{
	size_t	i;

	i = 0;
	while (i < cnt)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static bool	allocate_word(char **strs, char const *s, char c)
{
	size_t	i;
	size_t	word_len;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			word_len = 0;
			while (s[word_len] && s[word_len] != c)
				word_len++;
			strs[i] = my_strndup(s, word_len);
			if (!strs[i])
				return (free_all(strs, i), false);
			i++;
			s += word_len;
		}
		while (*s && *s == c)
			s++;
	}
	strs[i] = NULL;
	return (true);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;

	if (!s)
		return (NULL);
	strs = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!strs)
		return (NULL);
	if (!allocate_word(strs, s, c))
		return (NULL);
	return (strs);
}

// #include <stdio.h>
// int	main()
// {
// 	char	*str = "";
// 	char	**spl = ft_split(str, 'z');

// 	for (int i = 0; i < 100; i++) {
// 		if (!spl[i])
// 		{
// 			printf("%d, %s\n", i, spl[i]);
// 			break ;
// 		}
// 		puts(spl[i]);
// 	}
// }