/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:02:26 by junmlee           #+#    #+#             */
/*   Updated: 2023/10/18 21:55:41 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_u;
	unsigned char	*cur;
	size_t			i;

	dst_u = dst;
	cur = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*dst_u = *cur;
		dst_u++;
		cur++;
		i++;
	}
	return (dst);
}
