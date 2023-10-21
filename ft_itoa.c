/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:19:20 by junmlee           #+#    #+#             */
/*   Updated: 2023/10/22 01:38:28 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*itoa_init(long a)
{
	char			*ret;
	unsigned int	len;

	len = 0;
	if (a < 0)
		len++;
	if (a == 0)
	{
		ret = (char *)malloc(sizeof(char) * 2);
		if (ret == NULL)
			return (NULL);
		ret[0] = '0';
		ret[1] = '\0';
		return (ret);
	}
	while (a != 0)
	{
		len++;
		a /= 10;
	}
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (NULL);
	return (ret);
}

void	arr_rev(char *arr)
{
	unsigned int	len;
	unsigned int	i;
	char			temp;

	len = 0;
	while (arr[len] != '\0')
		len++;
	i = 0;
	while (i < (len / 2))
	{
		temp = arr[i];
		arr[i] = arr[len - i - 1];
		arr[len - i - 1] = temp;
		i++;
	}
	return ;
}

char	*ft_itoa(int n)
{
	char			*arr;
	unsigned int	i;
	long			a;

	arr = itoa_init((long)n);
	if (arr == NULL)
		return (NULL);
	if (n == 0)
		return (arr);
	i = 0;
	a = n;
	if (n < 0)
		a = -a;
	while (a != 0)
	{
		arr[i] = a % 10 + '0';
		i++;
		a /= 10;
	}
	if (n < 0)
		arr[i++] = '-';
	arr[i] = '\0';
	arr_rev(arr);
	return (arr);
}
