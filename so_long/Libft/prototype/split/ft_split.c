#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int	ft_count_words(const char *s, char c)
{
	int	word_num;

	word_num = 0;
	while (*s)
	{
        if (*s && *s != c)
        {
            word_num++;
            while (*s && *s != c)
                s++;
            if (!*s)
                break;
        }
        s++;
	}
	return (word_num);
}

static char	**ft_assign_words(const char *s, char c, char **arr)
{
	int	i;
    char    *start_of_the_word;
    size_t  char_num;

    i = 0;
    char_num = 0;
    while (*s)
    {
        if (*s && *s != c)
        {
            start_of_the_word = (char *)s;
            while (*s && *s != c)
            {
                char_num++;
                s++;
            }
            arr[i] = (char *)malloc(sizeof(char) * (char_num + 1));
            if (!arr[i])
                return (NULL);
            strlcpy(arr[i++], start_of_the_word, (char_num + 1));
            char_num = 0;
            if (!*s)
                break;
        }
        s++;
    }
	arr[i] = 0;
	return (arr);
}

char **ft_split(const char *s, char c)
{
	char	**result;
	int	the_word_num;

	if (!s)
		return (NULL);
	the_word_num = ft_count_words(s, c);
    printf("the word num: %d\n", the_word_num);
	result = (char **)malloc(sizeof(char *) * (the_word_num + 1));
	if (!result)
    {
      printf("can't alloc\n");
      return (NULL);
    }
	ft_assign_words(s, c, result);
	return (result);
}

int main()
{
  char *string = "                  olol";
  char **result = ft_split(string, ' ');

  printf("----the result----\n");
  for (int j = 0; result[j]; j++)
      printf("-> %s\n", result[j]);
  return (0);
}
