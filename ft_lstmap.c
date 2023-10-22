/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:01:08 by junmlee           #+#    #+#             */
/*   Updated: 2023/10/22 10:08:53 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*_lstnew(void *content)
{
	t_list	*add;

	add = (t_list *)malloc(sizeof(t_list));
	if (add == NULL)
		return (NULL);
	add->next = NULL;
	add->content = content;
	return (add);
}

void	_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		temp = *lst;
		*lst = (*lst)->next;
		del(temp->content);
		free(temp);
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*cur;
	t_list	*temp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	ret = _lstnew(f(lst->content));
	if (ret == NULL)
		return (NULL);
	cur = ret;
	lst = lst->next;
	while (lst)
	{
		temp = _lstnew(f(lst->content));
		if (temp == NULL)
		{
			_lstclear(&ret, del);
			return (NULL);
		}
		cur->next = temp;
		cur = temp;
		lst = lst->next;
	}
	return (ret);
}
