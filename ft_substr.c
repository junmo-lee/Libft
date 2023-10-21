/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:45:49 by junmlee           #+#    #+#             */
/*   Updated: 2023/10/22 01:17:53 by junmlee          ###   ########.fr       */
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

void	_strcpy(char const *s, char *arr, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		arr[i] = s[start + i];
		i++;
	}
	arr[i] = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*arr;

	if (s == NULL)
		return (NULL);
	if (find_s_len(s) < start)
	{
		arr = (char *)malloc(sizeof(char));
		if (arr == NULL)
			return (NULL);
		*arr = '\0';
		return (arr);
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (arr == NULL)
		return (NULL);
	_strcpy(s, arr, start, len);
	return (arr);
}
