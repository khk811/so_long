#include <stdio.h>
#include <ctype.h>

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

int	main()
{
	char	c = '*';

	printf("isprint result: %d\n", isprint(c));
	printf("ft_isprint result: %d\n", ft_isprint(c));
	return (0);
}
