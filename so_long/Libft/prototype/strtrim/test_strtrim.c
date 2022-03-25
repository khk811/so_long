#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int  ft_trim_len(char const *s1, char const *set)
{
  int   i;
  int   result;

  i = 0;
  result = (int)strlen(s1);
  while (strchr(set, s1[i++]))
  {
    if (!result)
      return (0);
    result--;
  }
  i = (int)strlen(s1);
  while (strchr(set, s1[--i]))
    result--;
  return (result);
}

char *ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	len;
	char *result;

	if (!set)
		return (strdup((char *)s1));
    len = ft_trim_len(s1, set);
    printf("the len: %d\n", len);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
    {
      printf("can't allocate\n");
      return (NULL);
    }
	i = 0;
	while (*s1)
	{
      if (strchr(set, s1[i]))
        i++;
      else
       {
         strlcpy(result, s1 + i, (len + 1));
         break ;
       }
    }
	return (result);
}

int main()
{
  char *s1 = "  \t \t \n   \n\n\n\t";
  char *s2 = "";
  char *ret = ft_strtrim(s1, " \n\t");

  printf("the result: %s\n", ret);
  printf("-----\n");
  printf("expected result: %s\n", s2);
  return (0);
}
