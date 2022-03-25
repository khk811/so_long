#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	main()
{
	char	*s1 = "this is a sample zzzzz";
	char	*s2 = "this is a sample string";

	printf("strncmp result: %d\n", strncmp(s1, s2, 18));
	printf("ft_strncmp result: %d\n", ft_strncmp(s1, s2, 18));
	return (0);
}	
