/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:01:41 by junmlee           #+#    #+#             */
/*   Updated: 2023/10/21 19:06:15 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

unsigned int	len_find(char const *s)
{
	unsigned int	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

int	is_in_set(char s, char const *set)
{
	if (set == NULL)
		return (0);
	while (*set != '\0')
	{
		if (s == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*_strdup(const char *s1, unsigned int len)
{
	char			*arr;
	unsigned int	i;

	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(arr + i) = *(s1 + i);
		i++;
	}
	*(arr + i) = '\0';
	return (arr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*arr;
	unsigned int	start;
	unsigned int	end;

	if (s1 == NULL || set == NULL || *s1 == '\0' || *set == '\0')
		return (_strdup("", 0));
	start = 0;
	while (s1[start] != '\0' && is_in_set(s1[start], set))
		start++;
	end = len_find(s1) - 1;
	while (s1[end] != '\0' && is_in_set(s1[end], set) && start < end)
		end--;
	arr = _strdup(s1 + start, end - start + 1);
	if (arr == NULL)
		return (NULL);
	return (arr);
}
