#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	casted_c;
	unsigned char *casted_s;
	size_t	i;

	casted_c = (unsigned char)c;
	casted_s = (unsigned char *)s;
	i = 0;
	while (*casted_s && i < n)
	{
		if (*casted_s == casted_c)
			return ((void *)casted_s);
		i++;
		casted_s++;
	}
	return (NULL);
}

int	main()
{
	int	*test1[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	char	test2[30] = "this is a sample text";

	printf("memchr result: %s\n", memchr(test1, 1, sizeof(int) * 3));
	printf("ft_memchr result: %s\n",ft_memchr(test1, 1, sizeof(int) * 3));
	printf("----\n");
	printf("memchr result: %s\n", memchr(test2, 'a', sizeof(char) * 10));
	printf("ft_memchr result: %s\n", ft_memchr(test2, 'a', sizeof(char) * 10));
	return (0);
}
