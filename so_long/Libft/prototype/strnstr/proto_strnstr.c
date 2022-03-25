#include <stdio.h>
#include <string.h>

char	*ft_strnstr(char *str, char *to_find, size_t len)
{
	size_t	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (i <= len)
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (str[i + j] == to_find[j])
			{
				if (to_find[j + 1] == '\0')
					return (&str[i]);
				j++;
			}
		}
		i++;
	}
	return (0);
}

int	main()
{
	char	*haystack;
	char	*needle;

	haystack = "there are some flowers on the ground";
	needle = "flowers";
	printf("strstr result: %s\n", strstr(haystack, needle));
	printf("strnstr result: %s\n", strnstr(haystack, needle, 23));
	printf("ft_strnstr result: %s\n", ft_strnstr(haystack, needle, 23));
	haystack = "dash dab dab dash slash dash flash";
	needle = "slash";
	printf("strstr result: %s\n", strstr(haystack, needle));
	printf("strnstr result: %s\n", strnstr(haystack, needle, 10));
	printf("ft_strnstr result: %s\n", ft_strnstr(haystack, needle, 10));
	return (0);
}
