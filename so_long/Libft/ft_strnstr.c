/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:24:14 by hyunkkim          #+#    #+#             */
/*   Updated: 2021/12/18 20:33:58 by hyunkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len-- > 0)
	{
		i = 0;
		while (haystack[i] == needle[i] && i <= len)
		{
			i++;
			if (!needle[i])
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
