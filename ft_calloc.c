/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:07:35 by junmlee           #+#    #+#             */
/*   Updated: 2023/10/18 22:40:17 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void			*arr;
	unsigned char	*data;
	size_t			bytes;

	bytes = count * size;
	arr = malloc(bytes);
	if (arr == NULL)
		return (NULL);
	data = (unsigned char *)arr;
	while (bytes > 0)
	{
		*data = 0;
		data++;
		bytes--;
	}
	return (arr);
}
