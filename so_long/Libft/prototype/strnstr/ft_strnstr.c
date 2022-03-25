#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int	j;

	i = 0;
	if (!needle)
		return ((char *)haystack);
	while (i <= len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j])
			{
				if (!needle[j + 1])
					return ((char *)&haystack[i]);
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
