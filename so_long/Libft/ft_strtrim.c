/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:27:52 by hyunkkim          #+#    #+#             */
/*   Updated: 2021/12/18 14:14:04 by hyunkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_trim_len(char const *s1, char const *set)
{
	int	i;
	int	result;

	i = 0;
	result = (int)ft_strlen(s1);
	while (ft_strchr(set, s1[i++]))
	{
		if (!result)
			return (0);
		result--;
	}
	i = (int)ft_strlen(s1);
	while (ft_strchr(set, s1[--i]))
		result--;
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	 int	len;
	char	*result;

	if (!s1)
		return (NULL);
	else if (!set)
		return (ft_strdup((char *)s1));
	len = ft_trim_len(s1, set);
	if (!len)
		return ((char *)ft_calloc(sizeof(char), 1));
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (*s1)
	{
		if (ft_strchr(set, *s1))
			s1++;
		else
		{
			ft_strlcpy(result, s1, (len + 1));
			break ;
		}
	}
	return (result);
}
