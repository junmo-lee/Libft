/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:23:31 by junmlee           #+#    #+#             */
/*   Updated: 2023/10/19 16:48:10 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *p, int c)
{
	char	*ret;
	char	find;

	find = (char)c;
	ret = NULL;
	while (1)
	{
		if (*p == find)
			ret = (char *)p;
		if (*p == '\0')
			return (ret);
		p++;
	}
}
