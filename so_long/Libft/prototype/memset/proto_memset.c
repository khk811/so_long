#include <stdio.h>
#include <string.h>

// https://st-lab.tistory.com/198
// https://dojang.io/mod/page/view.php?id=552; void pointer as a parameter in a function.
// https://stackoverflow.com/questions/19707820/memset-not-working

void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned char	casted_c;
	size_t i;

	i = 0;
	casted_c = (unsigned char)c;
	while (i < len)
		*(unsigned char *)(dest + (i++)) = casted_c;
	// how the fuck did i write this wft why is this working????
	return (dest);
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
