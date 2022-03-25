#include <stdio.h>
#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
		*(unsigned char *)(b + (i++)) = c;
	return (b);
}

int	main()
{
	int	memset_Ptr[10];
	int	ft_memset_Ptr[10];

	memset(memset_Ptr, 1, 10 * sizeof(int));
	ft_memset(ft_memset_Ptr, 1, 10 * sizeof(int));
	for (int i = 0; i < 10; i++)
	{
		printf("memset: %d ", memset_Ptr[i]);
		printf("ft_memset: %d\n", ft_memset_Ptr[i]);
	}
	return (0);
}
