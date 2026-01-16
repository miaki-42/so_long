/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 02:21:28 by komatsuk          #+#    #+#             */
/*   Updated: 2026/01/17 02:44:50 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// 厳密には、get_next_lineがEOFまで読んでNULLを返した or エラーが起きてNULLを返した、どちらか分からないな...
static t_list	*create_maplst(int fd)
{
	t_list	*maplst;
	t_list	*node;
	char	*line;
	char	*nlp;

	maplst = NULL;
	line = get_next_line(fd);
	while (line)
	{
		nlp = ft_strchr(line, '\n');
		if (nlp)
			*nlp = '\0';
		node = ft_lstnew(line);
		if (!node)
			return (ft_lstclear(&maplst, free), NULL);
		ft_lstadd_back(&maplst, node);
		line = get_next_line(fd);
	}
	return (maplst);
}

t_list	*read_mapfile(char *filename)
{
	t_list  *maplst;
	int	 fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	maplst = create_maplst(fd);
	if (!maplst)
		return (close(fd), NULL);
	return (close(fd), maplst);
}
