#include "../minishell.h"


int ft_strcmp(char *s1, char *s2)
{
	if(!s1 || !s2)
		return -1;
	int i =0;
	while((s1[i] == s2[i]) && s1[i] && s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);

}
