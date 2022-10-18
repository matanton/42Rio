#include <unistd.h>

void hidenp (char *s1, char *s2)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (s1[i] != '\0')
	{
		while (s1[i] != s2[k] && s2[k] != '\0')
			k++;
		if (s2[k] == '\0')
		{
			write(1,"0",1);
			return ;
		}
		i++;
		k++;
	}
	write(1,"1",1);
}

int main (int argc, char **argv)
{
	if(argc == 3)
		hidenp(argv[1], argv[2]);
	write (1,"\n",1);
	return 0;
}
