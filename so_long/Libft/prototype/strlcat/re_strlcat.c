/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:19:19 by hyunkkim          #+#    #+#             */
/*   Updated: 2021/12/14 15:20:18 by hyunkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (*dst && i < dstsize)
		dst++;
	while (*src && i + 1 < dstsize)
	{
		dst[i++] = *src;
		dst++;
		src++;
	}
	while (*src)
	{
		++i;
		++src;
	}
	return (i);
}

int main()
{
	char	dest1[30];
	char	*src1 = "AAAAAAAAA";
	char	dest2[30];
	char	*src2 = "AAAAAAAAA";

	memset(dest1, 'C', 5);
	memset(dest2, 'C', 5);
	//dest1[0] = 'B';
	//dest2[0] = 'B';
	printf("dest len: %lu\n", strlen(dest1));
	printf("src len: %lu\n", strlen(src1));
	printf("%lu\n", ft_strlcat(dest1, src1, -1));
	printf("ft_ result: %s\n", dest1);
	printf("%lu\n", strlcat(dest2, src2, 10));
	printf("strlcat result: %s\n", dest2);

	return (0);
}
