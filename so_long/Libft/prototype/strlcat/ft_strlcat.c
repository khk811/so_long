/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:19:19 by hyunkkim          #+#    #+#             */
/*   Updated: 2021/12/13 18:05:37 by hyunkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dest, char *src, size_t dest_size)
{
	int	src_len_to_add;
	int	idx_dest;
	int	idx_src;
	int	normal_return;

	src_len_to_add = (int)(dest_size - strlen(dest)) - 1;
	idx_dest = strlen(dest);
	idx_src = 0;
	normal_return = (int)(strlen(dest) + strlen(src));
	if (src_len_to_add < 0)
	{
		printf("src_len is minus\n");
		printf("strlen(src) + dest_size: %lu\n", strlen(src) + dest_size);
		return (strlen(src) + dest_size);
	}
	while (src[idx_src] != '\0' && src_len_to_add > 0)
	{
		dest[idx_dest++] = src[idx_src++];
		src_len_to_add--;
	}
	dest[idx_dest] = '\0';
	return (normal_return);
}

int main()
{
	char	dest1[30];
	char	*src1 = "AAAAAAAAA";

	memset(dest1, 0, 30);
	memset(dest1, 'C', 5);
	printf("dest len: %lu\n", strlen(dest1));
	printf("src len: %lu\n", strlen(src1));
	printf("%lu\n", ft_strlcat(dest1, src1, -1));
	printf("ft_ result: %s\n", dest1);

	return (0);
}
