/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: komatsuk <komatsuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 22:05:02 by komatsuk          #+#    #+#             */
/*   Updated: 2025/10/22 19:53:59 by komatsuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*new;
	void	*new_content;

	newlst = NULL;
	if (f && del)
	{
		while (lst)
		{
			new_content = f(lst->content);
			new = ft_lstnew(new_content);
			if (!new)
			{
				free(new_content);
				ft_lstclear(&newlst, del);
				return (NULL);
			}
			ft_lstadd_back(&newlst, new);
			lst = lst->next;
		}
	}
	return (newlst);
}
