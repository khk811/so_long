#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	// dst == src -> in this case, handling exception is nessesaire.
	// overlapping may occur in this case.
	
}

int	main()
{
	char	dest[35] = "ok, something in the destination";
	char	source[25] = "from source, with love";

	printf("memmove result: %s\n", memmove(dest, source, 12));
	return (0);
}
