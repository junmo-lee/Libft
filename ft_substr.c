/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:45:49 by junmlee           #+#    #+#             */
/*   Updated: 2023/10/19 17:51:05 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

unsigned int	find_s_len(char const *s)
{
	unsigned int	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*arr;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	if (start >= find_s_len(s))
	{
		arr = (char *)malloc(sizeof(char));
		*arr = '\0';
		return (arr);
	}
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		arr[i] = s[start + i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
