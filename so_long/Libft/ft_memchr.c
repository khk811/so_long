/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:51:25 by hyunkkim          #+#    #+#             */
/*   Updated: 2021/12/18 15:31:34 by hyunkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	       size_t	i;
	unsigned char	uc_c;
	unsigned char	*uc_s;

	i = 0;
	uc_c = (unsigned char)c;
	uc_s = (unsigned char *)s;
	while (i < n)
	{
		if (*uc_s == uc_c)
			return ((void *)uc_s);
		i++;
		uc_s++;
	}
	return (NULL);
}
