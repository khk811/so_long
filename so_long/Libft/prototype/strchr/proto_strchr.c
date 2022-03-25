#include <stdio.h>
#include <string.h>

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (&str[i]);
}

int	main()
{
	char	*str1 = "this is a sample string";

	printf("strchr result: %s\n", strchr(str1, (int)'a'));
	printf("ft_strchr result: %s\n", ft_strchr(str1, (int)'a'));
	return (0);
}
