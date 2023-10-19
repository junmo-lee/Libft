/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:43:01 by junmlee           #+#    #+#             */
/*   Updated: 2023/10/20 05:36:38 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

unsigned int	_find_len(char const *s)
{
	unsigned int	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

void	_strcat(char *arr, char const *s, unsigned int _len)
{
	unsigned int	i;

	i = 0;
	while (*(s + i) != '\0' && i < _len)
	{
		*arr = *(s + i);
		i++;
		arr++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	s1_len;
	unsigned int	s2_len;
	char			*arr;

	s1_len = _find_len(s1);
	s2_len = _find_len(s2);
	arr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (arr == NULL)
		return (NULL);
	_strcat(arr, s1, s1_len);
	_strcat(arr + s1_len, s2, s2_len);
	*(arr + s1_len + s2_len) = '\0';
	return (arr);
}
