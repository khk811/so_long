#include <stdio.h>
#include <string.h>

//size_t	ft_strlcat(char *dest, char *src, size_t dest_size);

int	main()
{
	char	paris[35] = "ecole42 et...";
	char	lyon[20] = "42lyon et...";
	char	nice[20] = "42nice et...";
	char	seoul[10] = "<42seoul>";

	printf("var. paris len: %d\n", (int)strlen(paris));
	printf("var. lyon len: %d\n", (int)strlen(lyon));
	printf("var. nice len: %d\n", (int)strlen(nice));
	printf("var. seoul len: %d\n", (int)strlen(seoul));
	printf("\n");
	printf("strlcat return value (paris <- seoul): %lu\n", strlcat(paris, seoul, strlen(paris) + strlen(seoul) + 3));
	printf("strlcat return value (lyon <- seoul): %lu\n", strlcat(lyon, seoul, strlen(lyon) + strlen(seoul) - 3));
	printf("strlcat return value (nice <- seoul): %lu\n", strlcat(nice, seoul, 7));
	printf("\n");
	printf("the result (paris <- seoul): %s\n", paris);
	printf("the result (lyon <- seoul): %s\n", lyon);
	printf("the result (nice <- seoul): %s\n", nice);
	printf("\n");
	printf("modified var. paris len: %d\n", (int)strlen(paris));
	printf("modified var. lyon len: %d\n", (int)strlen(lyon));
	printf("modified var. nice len: %d\n", (int)strlen(nice));
	return (0);
}
