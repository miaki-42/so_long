/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 01:47:47 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/07 01:53:49 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int	printchar(int c);
int	printstr(const char *s);
int	printnbr(int n);
int	printnbr_ui(unsigned int n);
int	printaddress(uintptr_t p);
int	printx(unsigned int n, char *basestr);

#endif