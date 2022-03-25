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

size_t	ft_strlcpy(char *dest, char *src, size_t dest_size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	i = 0;
	while (src[i] != '\0' && i + 1 < dest_size)
	{
		dest[i] = src[i];
		i++;
	}
	if (dest_size > 0)
		dest[i] = '\0';
	return (src_len);
}

int	main()
{
	char	paris[40] = "France, Paris. this is a destination";
	char	lyon[40] = "another dest, lyon";
	char	seoul[20] = "Hello from Seoul";


	strlcpy(paris, seoul, ft_strlen(seoul) + 1);
	printf("meanwhile in Paris: %s\n", paris);
	
	ft_strlcpy(lyon, seoul, ft_strlen(seoul) + 1);
	printf("meanwhile in Lyon: %s\n", lyon);

	return (0);
}	
