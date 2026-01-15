/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:23:17 by komatsuk          #+#    #+#             */
/*   Updated: 2025/11/04 16:58:53 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	mimic_getc(int fd)
{
	static t_buf	save;

	if (save.size == 0)
	{
		save.ofset = save.buf;
		save.size = read(fd, save.buf, BUFFER_SIZE);
		if (save.size == -1)
		{
			save.size = 0;
			return (ERROR);
		}
		if (save.size == 0)
			return (EOF);
	}
	save.size--;
	return (*save.ofset++);
}

static int	mimic_putc(int c, t_line *line)
{
	char	*new;
	size_t	i;

	if (line->memsize == 0 || line->size == line->memsize - 1)
	{
		new = malloc(line->memsize + MALLOC_SIZE);
		if (!new)
			return (EOF);
		if (line->str)
		{
			i = 0;
			while (i < line->size)
			{
				new[i] = (line->str)[i];
				i++;
			}
			free(line->str);
		}
		line->str = new;
		line->memsize += MALLOC_SIZE;
	}
	line->str[line->size] = c;
	line->size++;
	return (c);
}

char	*get_next_line(int fd)
{
	t_line	line;
	int		c;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > SIZE_MAX)
		return (NULL);
	line.str = NULL;
	line.size = 0;
	line.memsize = 0;
	while (true)
	{
		c = mimic_getc(fd);
		if (c == ERROR)
			return (free(line.str), NULL);
		else if (c == EOF)
			break ;
		if (mimic_putc(c, &line) == EOF)
			return (free(line.str), NULL);
		if (c == '\n')
			break ;
	}
	if (line.size > 0)
		line.str[line.size] = '\0';
	return (line.str);
}
