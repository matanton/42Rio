#include <unistd.h>

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return(0);
}

int	main (int argc, char **argv)
{
	int	i;
	char	*str;

	str = argv[1];

	i = 0;
	if (argc == 2)
	{
		while (is_space(str[i]) == 1 && str[i] != '\0')
			i++;
		while (is_space(str[i]) == 0 && str[i] != '\0')
		{
			write (1,&str[i],1);
			i++;
		}
	write (1,"\n",1);
	return (0);
	}
	else
		write(1,"\n",1);
}

