/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:07:29 by hyunkkim          #+#    #+#             */
/*   Updated: 2021/12/18 14:03:08 by hyunkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	word_num;

	word_num = 0;
	while (*s)
	{
		if (*s && *s != c)
		{
			word_num++;
			while (*s && *s != c)
				s++;
			if (!*s)
				break ;
		}
		s++;
	}
	return (word_num);
}

static char	**ft_free_heap(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
	s = NULL;
	return (NULL);
}

static char	**ft_assign_words(const char *s, char c, char **arr)
{
	 int	i;
	char	*word_start;

	i = 0;
	while (*s)
	{
		if (*s && *s != c)
		{
			word_start = (char *)s;
			while (*s && *s != c)
				s++;
			arr[i] = (char *)malloc(sizeof(char) * ((s - word_start) + 1));
			if (!arr[i])
				return (ft_free_heap(arr));
			ft_strlcpy(arr[i++], word_start, ((s - word_start) + 1));
			if (!*s)
				break ;
		}
		s++;
	}
	arr[i] = 0;
	return (arr);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	 int	the_word_num;

	if (!s)
		return (NULL);
	the_word_num = ft_count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (the_word_num + 1));
	if (!result)
		return (NULL);
	if (!ft_assign_words(s, c, result))
		return (NULL);
	return (result);
}
