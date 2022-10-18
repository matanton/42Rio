#include <unistd.h>

int is_space(char c)
{
	if (c == ' ' || c == '\n')
		return 0;
	return 1;
}

int	ft_strlen(char *s)
{
	int		len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		int i;
		char *str;
		str = argv[1];

		i = ft_strlen(str) - 1;
		while (is_space(str[i]) == 0)
			i--;
		while (is_space(str[i]) == 1)
			i--;
		i++;
		while (is_space(str[i]) == 1)
		{
			write (1,&str[i],1);
			i++;
		}
	write(1,"\n",1);
	return 0;
	}
}
