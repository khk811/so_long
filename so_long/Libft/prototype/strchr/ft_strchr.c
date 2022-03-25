#include <stdio.h>
#include <string.h>

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

int	main()
{
	char	*str1 = "this is a sample string";

	printf("strchr result: %s\n", strchr(str1, (int)'i'));
	printf("ft_strchr result: %s\n", ft_strchr(str1, (int)'i'));
	return (0);
}
