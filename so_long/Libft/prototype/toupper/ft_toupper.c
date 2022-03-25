#include <stdio.h>

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

int	main()
{
	char	c;

	c = 122;
	printf("the input: %c\n", c);
	printf("the result: %c\n", ft_toupper(c));
	return (0);
}
