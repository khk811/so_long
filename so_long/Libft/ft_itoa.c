/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkkim <hyunkkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:39:32 by hyunkkim          #+#    #+#             */
/*   Updated: 2021/12/18 13:22:15 by hyunkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_count_digits(long n)
{
	long	result;

	result = 0;
	if (n < 0)
	{
		n *= -1;
		result++;
	}
	while (n > 9)
	{
		n /= 10;
		result++;
	}
	result++;
	return (result);
}

static long	ft_make_divisor(long n)
{
	 int	i;
	long	result;

	result = 1;
	i = ft_count_digits(n);
	if (n < 0)
		i--;
	while (--i > 0)
		result *= 10;
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	 int	i;
	long	divisor;
	long	long_n;

	i = 0;
	long_n = (long)n;
	divisor = ft_make_divisor(long_n);
	result = (char *)malloc(sizeof(char) * (ft_count_digits(long_n) + 1));
	if (!result)
		return (NULL);
	if (long_n < 0)
	{
		result[i++] = '-';
		long_n *= -1;
	}
	while (divisor > 0)
	{
		result[i++] = (long_n / divisor) + '0';
		long_n %= divisor;
		divisor /= 10;
	}
	result[i] = '\0';
	return (result);
}
