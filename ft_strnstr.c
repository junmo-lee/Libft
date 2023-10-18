/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:07:46 by junmlee           #+#    #+#             */
/*   Updated: 2023/10/18 23:01:01 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str;
	char	*to_find;
	char	*start;
	size_t	i;

	str = (char *)haystack;
	to_find = (char *)needle;
	if (*to_find == '\0')
		return ((char *)haystack);
	i = 0;
	while (*(str + i) != '\0' || i < len)
	{
		start = str + i;
		while (*start == *to_find)
		{
			start++;
			to_find++;
		}
		if (*to_find == '\0')
			return (str + i);
		i++;
	}
	return (0);
}
