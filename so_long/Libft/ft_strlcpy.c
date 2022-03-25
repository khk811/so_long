/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:19:37 by hyunkkim          #+#    #+#             */
/*   Updated: 2021/12/18 13:04:49 by hyunkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	result;

	result = ft_strlen(src);
	if (!dstsize)
		return (result);
	while (*src && --dstsize)
		*dst++ = *src++;
	if (dstsize >= 0)
		*dst = '\0';
	return (result);
}
