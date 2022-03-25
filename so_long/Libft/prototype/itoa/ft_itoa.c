#include <stdlib.h>
#include <stdio.h>

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

static long ft_make_divider(long n)
{
	int	i;
	long	result;

	result	= 1;
	i = ft_count_digits(n);
	if (n < 0)
		i--;
	while (--i > 0)
		result *= 10;
	return (result);
}

char *ft_itoa(int n)
{
	char	*result;
	long	the_divider;
	 int	i;
    long    long_n;
	
	i = 0;
    long_n = (long)n;
	the_divider = ft_make_divider(long_n);
	result = (char *)malloc(sizeof(char) * (ft_count_digits(long_n) + 1));
	if (!result)
		return (NULL);
	if (long_n < 0)
	{
		result[i++] = '-';
		long_n *= -1;
	}
	while (the_divider > 0)
	{
		result[i++] = (long_n / the_divider) + '0';
		long_n %= the_divider;
		the_divider /= 10;
	}
	result[i] = '\0';
	return (result);
}

int main()
{
    int int_min = -2147483648;

    printf("ft_itoa result: %s\n", ft_itoa(int_min));
    return (0);
}
