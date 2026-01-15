/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:23:33 by komatsuk          #+#    #+#             */
/*   Updated: 2025/12/07 01:55:13 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define ERROR -2
# define MALLOC_SIZE 1024

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdint.h>

typedef struct s_buf
{
	char	buf[BUFFER_SIZE];
	char	*ofset;
	ssize_t	size;
}	t_buf;

typedef struct s_line
{
	char	*str;
	size_t	size;
	size_t	memsize;
}	t_line;

#endif