/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:42:09 by junmlee           #+#    #+#             */
/*   Updated: 2023/10/13 15:36:09 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*memset(void *b, int c, size_t len)
{
	unsigned char	*arr;
	size_t			i;

	arr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		*arr = c;
		arr++;
		i++;
	}
	return (b);
}
