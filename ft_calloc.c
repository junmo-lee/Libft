/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:07:35 by junmlee           #+#    #+#             */
/*   Updated: 2023/10/22 00:56:36 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	_bzero(void *b, size_t len)
{
	unsigned char	*data;
	size_t			i;

	data = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		*data = 0;
		data++;
		i++;
	}
	return ;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if ((count * size) / size != count
		|| count >= INT32_MAX || size >= INT32_MAX)
		return (NULL);
	arr = malloc(count * size);
	if (arr == NULL)
		return (NULL);
	_bzero(arr, count * size);
	return (arr);
}
