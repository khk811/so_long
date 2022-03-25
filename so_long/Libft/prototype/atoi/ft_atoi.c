#include <stdio.h>
#include <stdlib.h>

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
        //printf("result in progress : %d\n", result);
		str++;
	}
	result *= sign;
	return (result);
}

int	main()
{
	char	*str;

	str = "999999999999999999999999999999999999007";
	printf("atoi result: %d\n", atoi(str));
	printf("ft_atoi result: %d\n", ft_atoi(str));
	return (0);
}
