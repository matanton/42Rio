#include <unistd.h>

int main(int argc, char **s)
{
	int i;

	i = 0;
	
	if (argc == 2)
	{
		while (s[1][i] != '\0')
		{
			if((s[1][i] >= 'a' && s[1][i] <= 'y') || (s[1][i] >= 'A' && s[1][i] <= 'Y'))
				s[1][i] = s[1][i] + 1;
			else if (s[1][i] == 'z'|| s[1][i] == 'Z')
				s[1][i] = s[1][i] - 25;
			write(1, &s[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
	

