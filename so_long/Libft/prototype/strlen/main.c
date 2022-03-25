#include <stdio.h>
#include <string.h>

int	ft_strlen(char *s);

int	main()
{
	char	*test1 = "asdf";
	char	test2[30] = "this is a sample string";

	printf("strlen result: %lu\n", strlen(test1));
	printf("ft_strlen result: %d\n", ft_strlen(test1));
	printf("----\n");
	printf("strlen result: %lu\n", strlen(test2));
	printf("ft_strlen result: %d\n", ft_strlen(test2));
	return (0);
}
