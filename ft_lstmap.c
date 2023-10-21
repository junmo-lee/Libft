/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:01:08 by junmlee           #+#    #+#             */
/*   Updated: 2023/10/21 14:43:18 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		del((*lst)->content);
		temp = (*lst)->next;
		free((*lst));
		*lst = temp;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*new;
	t_list	*i;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	ret = NULL;
	while (lst != NULL)
	{
		new = (t_list *)malloc(sizeof(t_list));
		if (new == NULL)
		{
			_lstclear(&ret, del);
			return (NULL);
		}
		new->content = f(lst->content);
		new->next = NULL;
		i = ret;
		while (i->next != NULL)
			i = i->next;
		i->next = new;
		lst = lst->next;
	}
	return (new);
}
