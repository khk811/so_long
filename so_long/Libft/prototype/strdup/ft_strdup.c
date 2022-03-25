#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*result;
	 int	i;

	i = 0;
	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!result)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int	main()
{
	char	*the_source = "sriracha";
	char	*resulte;

	resulte = ft_strdup(the_source);
	printf("the result: %s\n", resulte);
	free(resulte);
	return (0);
}
