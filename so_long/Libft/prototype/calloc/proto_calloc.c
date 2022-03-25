#include <stdlib.h>
#include <stdio.h>

/*
 * calloc안에 뭐가 들어가는지 알아야함.
 * 이제 문자 ascii code :0 -> '\0'인지, 
 * 아니면 숫자 '0'인지 뭔지 모르겠음. 
 * 뭘 0으로 초기화한다는거임????
 *
 * https://stackoverflow.com/questions/3449031/c-calloc-v-malloc
 *
 * With malloc, if you want to guarantee the same effect you'd have to call something like memset to reset the memory, e.g.

char* buffer = (char*)malloc(100);
memset(buffer,0,100);
 *
 */

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	int	i;

	result = (void *)malloc(count * size);
	while (i < count)
	{
		result[i] = 0;
		i++;
	}
	return (result);
}


int	main()
{
	int	*test_calloc;
	int	i;
	int	test_size;

	test_size = 10;
	test_calloc = (int *)calloc(test_size, sizeof(int));
	test_ft_calloc = (int *)ft_calloc(test_size, sizeof(int));
	i = 0;
	if(test_calloc != NULL && test_ft_calloc != NULL)
	{
		while (i < test_size)
		{
			printf("test_calloc[%d]: %d\n", i, test_calloc[i]);
			printf("test_ft_calloc[%d]: %d\n\n", i, test_ft_calloc[i]);
			i++;
		}
	}
	else
		printf("main failed");
	free(test_calloc);
	free(test_ft_calloc);
	return (0);
}
