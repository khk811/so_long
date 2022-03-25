#include <stdio.h>
#include <string.h>

static void	*ft_memset(void *b, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
		*(unsigned char *)(b + (i++)) = c;
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

int	main()
{
	int	test_mem_ptr[10];
	int	test_mem_ptr2[10];
	int	i;

	i = 0;
	bzero(test_mem_ptr, sizeof(int) * 10);
	ft_bzero(test_mem_ptr2, sizeof(int) * 10);
	while (i < 10)
	{
		printf("bzero result: %d ", test_mem_ptr[i]);
		printf("ft_bzero result :%d\n", test_mem_ptr2[i]);
		i++;
	}
	return (0);
}
