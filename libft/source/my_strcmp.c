/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 16:14:46 by komatsuk          #+#    #+#             */
/*   Updated: 2026/01/20 16:14:55 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_strcmp(const char *s1, const char *s2)
{
	unsigned char	*ucs1;
	unsigned char	*ucs2;

	ucs1 = (unsigned char *)s1;
	ucs2 = (unsigned char *)s2;
	while (*ucs1 && *ucs1 == *ucs2)
	{
		ucs1++;
		ucs2++;
	}
	return (*ucs1 - *ucs2);
}
