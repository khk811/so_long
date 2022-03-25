#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	//what's the diff. w/memmove and memcpy??
}

int	main()
{
	char	dest[35] = "ok, something in the destination";
	char	source[25] = "from source, with love";

	printf("memmove result: %s\n", memmove(dest, source, 12));
	return (0);
}
