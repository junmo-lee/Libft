/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:07:46 by junmlee           #+#    #+#             */
/*   Updated: 2023/10/13 18:17:35 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*strstr(const char *haystack, const char *needle)
{
	char	*str;
	char	*to_find;
	char	*start;

	str = haystack;
	to_find = needle;

	if (*to_find == '\0')
		return (haystack);

	while (*str != '\0')
	{
		start = str;
		while (*start == *to_find)
		{
			start++;
			to_find++;
		}
		if (*to_find == '\0')
			return (str);
		str++;
	}
	return (0);
}
