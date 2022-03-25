#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dst);
}


int	main()
{
	char	hot_sauce[20] = "sriracha";
	char	sandwich[30] = "________ inside BTL";
	char	pizza[40] = "________ on pepperoni pizza";
	int	reset_num[11] = {0,0,0,0,0,0,0,0,0,0,0};
	int	phone_num_1[11] = {0,1,0,1,2,3,4,5,6,7,8};
	int	phone_num_2[11] = {0,1,0,8,7,6,5,4,3,2,1};

	printf("----hot sauce with foods----\n");
	printf("sandwich before putting sauce: %s\n", sandwich);
	printf("pizza before putting sauce: %s\n", pizza);
	memcpy(sandwich, hot_sauce, 8);
	ft_memcpy(pizza, hot_sauce, 8);
	printf("sandwich after putting sauce: %s\n", sandwich);
	printf("pizza after putting sauce: %s\n", pizza);
	printf("\n\n");
	printf("----WOW NUMBERS----\n");
	for (int i = 0; i < 11; i++)
		printf("%d", phone_num_1[i]);
	printf("\n");
	for (int i = 0; i < 11; i++)
		printf("%d", phone_num_2[i]);
	printf("\n");
	memcpy(phone_num_1, reset_num, 7 * sizeof(int));
	ft_memcpy(phone_num_2, reset_num, 7 * sizeof(int));
	printf("\n");
	printf("\n");
	for (int i = 0; i < 11; i++)
		printf("%d", phone_num_1[i]);
	printf("\n");
	for (int i = 0; i < 11; i++)
		printf("%d", phone_num_2[i]);
	printf("\n");
	return (0);
}
