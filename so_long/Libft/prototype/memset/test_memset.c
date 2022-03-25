#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main()
{
	int	numPtr[10];

	memset(numPtr, 0, 10 * sizeof(int));
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", numPtr[i]);
		printf(" -> ");
		printf("address of numPtr: %p\n", numPtr + i);
	}
	//free(numPtr);
	printf("\n");
	return (0);
}
