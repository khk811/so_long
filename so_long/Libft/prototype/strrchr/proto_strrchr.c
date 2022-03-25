#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrchr(char *str, int c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (str[len - i - 1] != 0)
	{
		if (str[len - i - 1] == c)
		{
			return (&str[len - i - 1]);
		}
		i++;
	}
	return (&str[len - i - 1]);
}

int	main()
{
	char	*str1 = "this is a sample text";

	printf("strrchr result: %s\n", strrchr(str1, (int)'s'));
	printf("ft_strrchr result: %s\n", ft_strrchr(str1, (int)'s'));
	return (0);
}
