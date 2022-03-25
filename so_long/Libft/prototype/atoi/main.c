#include <stdlib.h>
#include <stdio.h>

int	main()
{
	static const char	*test = "01  23";
	static const char	*test0 = "  0123";
	static const char	*test1 = "- 0123";
	static const char	*test2 = " -0123";
	static const char	*test3 = "++0123";

	printf("atoi result: %d\n", atoi(test));
	printf("atoi result: %d\n", atoi(test0));
	printf("atoi result: %d\n", atoi(test1));
	printf("atoi result: %d\n", atoi(test2));
	printf("atoi result: %d\n", atoi(test3));
	return (0);
}
