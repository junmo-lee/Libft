/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:01:08 by junmlee           #+#    #+#             */
/*   Updated: 2023/10/22 03:08:19 by junmlee          ###   ########.fr       */
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

	if (lst == NULL)
		return (NULL);
	ret = (t_list *)malloc(sizeof(t_list));
	if (ret == NULL)
		return (NULL);
	cur = ret;
	while (lst != NULL)
	{
		cur->content = f(lst->content);
		cur->next = malloc(sizeof(t_list));
		if (cur->next == NULL)
		{
			_lstclear(&cur, del);
			return (NULL);
		}
		cur = cur->next;
		lst = lst->next;
	}
	return (ret);
}
