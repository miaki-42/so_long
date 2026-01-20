/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 17:00:40 by komatsuk          #+#    #+#             */
/*   Updated: 2025/10/19 17:03:29 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_islower(int c)
{
	return ('a' <= c && c <= 'z');
}

int	ft_toupper(int c)
{
	if (ft_islower(c))
		return ('A' + c - 'a');
	return (c);
}
