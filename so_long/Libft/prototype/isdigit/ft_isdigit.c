#include <stdio.h>
#include <ctype.h>

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	main()
{
	int	d = -1;

	printf("the char: %c\n", (char)d);
	printf("isdigit result: %d\n", isdigit(d));
	printf("ft_isdigit result: %d\n", ft_isdigit(d));
	return (0);
}
