#include <stdio.h>

int	ft_tolower(char c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	//type casting ???
	return (c);
}

int	main()
{
	char	c = 65;

	printf("the input: %c\n", c);
	printf("the result: %c\n", ft_tolower(c));
	return (0);
}
