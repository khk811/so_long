#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;

	if (start + len > strlen(s) + 1)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	strlcpy(result, &s[start], (len + 1));
	return (result);
}

int	main()
{
	char *str = "01234";
	size_t size = 10;
	char *ret = ft_substr(str, 10, size);

	printf("result: %s\n", ret);
	return (0);
}
