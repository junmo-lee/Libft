/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:35:08 by junmlee           #+#    #+#             */
/*   Updated: 2023/10/18 20:37:16 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*_add_word(const char *s1, const char c)
{
	size_t	len;
	size_t	i;
	char	*arr;

	len = 0;
	while (*(s1 + len) != c)
		len++;
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(arr + i) = *(s1 + i);
		i++;
	}
	return (arr);
}


void	*free_and_null(char **arr)
{
	unsigned int	i;

	i = 0;
	while (*(arr + i) != NULL)
	{
		free(*(arr + i));
		i++;
	}
	free(arr);
	return (NULL);
}

char	**split_init(char const *s, char c)
{
	unsigned int	i;
	unsigned int	cnt;
	char			**ret;

	cnt = 0;
	i = 1;
	while (*(s + i) != '\0')
	{
		if (*(s + i - 1) != c && *(s + i) == c)
			cnt++;
		i++;
	}
	if (*(s + i - 1) != c)
		cnt++;
	ret = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (ret == NULL)
		return (NULL);
	if (*s != c)
	{
		*ret = _add_word(s, c);
		if (*ret == NULL)
			return (free_and_null(ret));
	}
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	word_cnt;
	char			**arr;

	arr = split_init(s, c);
	if (*s != c)
		word_cnt = 1;
	else
		word_cnt = 0;
	i = 1;
	while (*(s + i) != '\0')
	{
		if (*(s + i - 1) == c && *(s + i) != c)
		{
			*(arr + word_cnt) = _add_word(s + i, c);
			if (*(arr + word_cnt) == NULL)
				return (free_and_null(arr));
			word_cnt++;
		}
		i++;
	}
	*(arr + word_cnt) = NULL;
	return (arr);
}
