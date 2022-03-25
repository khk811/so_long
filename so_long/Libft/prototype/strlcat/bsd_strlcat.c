#include <string.h>
#include <stdio.h>

size_t	bsd_strlcat(char *dst, const char *src, size_t dstsize)
{
	const char	*odst;
	const char	*osrc;
	size_t	n;
	size_t	dlen;

	odst = dst;
	osrc = src;
	n = dstsize;
	while (n-- != 0 && *dst != '\0')
		dst++;
	dlen = dst - odst;
	n = dstsize - dlen;
	if (n-- == 0)
		return (dlen + strlen(src));
	while (*src != '\0')
	{
		if (n != 0)
		{
			*dst++ = *src;
			n--;
		}
		src++;
	}
	*dst = '\0';
	return (dlen + (src - osrc));
}

int	main()
{
	char	dest1[30] = "rrrrr";
	char	*src1 = "lorem ipsum dolor s:it amet";

	printf("bsd_result : %zu\n", bsd_strlcat(dest1, src1, 3));
	printf("expected : %s\n", dest1);
	return (0);
}
