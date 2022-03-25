#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

int	main()
{
	int	c = 42;

	printf("the char: %c\n", (char)c);
	printf("isalnum result: %d\n", isalnum(c));
	printf("ft_isalnum result: %d\n", ft_isalnum(c));
	return (0);
}
