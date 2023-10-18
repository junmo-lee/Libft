/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:01:41 by junmlee           #+#    #+#             */
/*   Updated: 2023/10/18 18:34:32 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	_find_len(char const *s)
{
	unsigned int	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

int	is_in_set(const char s, char const *set, unsigned int set_len)
{
	unsigned int	i;

	i = 0;
	while (i < set_len)
	{
		if (s == *(set + i))
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	s1_len;
	unsigned int	set_len;
	unsigned int	i;
	char			*arr;

	s1_len = _find_len(s1);
	set_len = _find_len(set);
	arr = (char *)malloc(sizeof(char) * (s1_len));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		if (is_in_set(*(s1 + i), set, set_len))
		{
			*arr = *(s1 + i);
			arr++;
		}
		i++;
	}
	*(arr + 1) = '\0';
	return (arr);
}
