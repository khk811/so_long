#include "so_long.h"

int	print_error(char *func, char *err_msg)
{
	printf("Error\n");
	printf("%s : ", func);
	printf("%s\n", err_msg);
	return (0);
}

void	*malloc_error(char *func)
{
	printf("Error\n");
	printf("%s : ", func);
	printf("%s\n", strerror(errno));
	return (NULL);
}

void	*mlx_error(char *func, char *err_msg)
{
	printf("Error\n");
	printf("%s : ", func);
	printf("%s\n", err_msg);
	return (NULL);
}
