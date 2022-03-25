#include <stdio.h>
#include <ctype.h>

int	ft_isupper(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}

int	ft_islower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	if (ft_isupper(c) || ft_islower(c))
		return (1);
	return (0);
}

int	main()
{
	int	c = 122;

	printf("the letter: %c\n", (char)c);
	printf("isalpha result: %d\n", isalpha(c));
	printf("ft_isalpha result: %d\n", ft_isalpha(c));
	return (0);
}
