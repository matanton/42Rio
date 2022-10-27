#include <unistd.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return(i);
}

int main (int argc, char **argv)
{
	char *str = argv[1];
	char s = argv[2][0];
	char r = argv[3][0];
	int d = 0;

	if(argc == 4)
	{
		if(ft_strlen(argv[2]) == 1 && ft_strlen(argv[3]) == 1)
		{
			while (str[d] != '\0')
			{
				if (str[d] != s)
					write(1,&str[d],1);
				else
					write(1,&r,1);
				d++;
			}
		}
	}
	write(1,"\n",1);
	return 0;
}
