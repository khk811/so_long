#include <stdio.h>
#include <stdlib.h>

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	count_minus;
	int	result;

	count_minus = 1;
	result = 0;
	while (ft_isspace(*str) || *str == '+')
		str++;
	if (*str == '-')
	{
		count_minus = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	result *= count_minus;
	return (result);
}

int	main()
{
	char	*str;

	str = "    ++-0123";
	printf("atoi result: %d\n", atoi(str));
	printf("ft_atoi result: %d\n", ft_atoi(str));
	return (0);
}
