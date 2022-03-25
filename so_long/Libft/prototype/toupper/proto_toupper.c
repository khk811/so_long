#include <stdio.h>

int	ft_toupper(char c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return ((int)c);
}

int	main()
{
	char	c = 114;

	printf("the input: %c\n", c);
	printf("the result: %c\n", ft_toupper(c));
	return (0);
}
