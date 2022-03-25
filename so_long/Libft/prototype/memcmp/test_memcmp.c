#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 +i))
			return (*(unsigned char *)(s1 +i) - *(unsigned char *)(s2 +i));
		i++;
	}
	return (0);
}

int	main()
{
	char	*s1 = "this is a sample ztring";
	char	*s2 = "this is a sample text";
	int	d1[2] = {42, 24};
	int	d2[2] = {42, 14};

	printf("---char---\n");
	printf("memcmp result: %d\n", memcmp(s1, s2, 18));
	printf("ft_memcmp result: %d\n", ft_memcmp(s1, s2, 18));
	printf("\n\n");
	printf("---int---\n");
	printf("memcmp result: %d\n", memcmp(d1, d2, 16));
	printf("ft_memcmp result: %d\n", ft_memcmp(d1, d2, 16));
	return (0);
}
