/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:27:52 by hyunkkim          #+#    #+#             */
/*   Updated: 2021/12/13 18:15:24 by hyunkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static int	ft_trim_len(char const *s1, char const *set)
{
	int	i;
	int	result;

	i = 0;
	result = (int)strlen(s1);
	while (strchr(set, s1[i++]))
	{
		if (!result)
			return (0);
		result--;
	}
	i = strlen(s1);
	while (strchr(set, s1[--i]))
		result--;
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	 int	len;
	char	*result;

	if (!set)
		return (strdup((char *)s1));
	if (!s1)
		return (NULL);
	len = ft_trim_len(s1, set);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (*s1)
	{
		if (strchr(set, *s1))
		{
			s1++;
			printf("address added\n");
		}
		else
		{
			strlcpy(result, s1, (len + 1));
			printf("break!\n");
			break ;
		}
	}
	if (!result[0])
	{
		result[0] = '\0';
		printf("null\n");
	}
	return (result);
}

int	main()
{
	char	*s;

	s = ft_strtrim("   xxx   xxx", " x");
	printf("result: %s\n", s);
	return (0);
}
