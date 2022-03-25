#include <stdio.h>
#include <string.h>

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	while (*src && --dstsize)
		*dst++ = *src++;
	if (dstsize > 0)
		*dst = '\0';
	return (ft_strlen(src));
}

int	main()
{
	char	paris[40] = "France, Paris. this is a destination";
	char	lyon[40] = "another dest, lyon";
	char	seoul[20] = "Hello from Seoul";
	int	i;


	i = 0;
	printf("before: %s\n", paris);
	printf("----\n");
	strlcpy(paris, seoul, ft_strlen(seoul) + 1);
	printf("meanwhile in Paris: %s\n", paris);
	
	printf("before: %s\n", lyon);
	printf("----\n");
	ft_strlcpy(lyon, seoul, ft_strlen(seoul) + 1);
	printf("meanwhile in Lyon: %s\n", lyon);
	while (seoul[i])
		printf("%c", seoul[i++]);
	printf("\n");
	return (0);
}	
