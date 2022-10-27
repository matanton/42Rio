int	is_add (char *str, char *nd)
{
	int first = atoi(st);
	int second = atoi(nd);
	return(first+second);
}

int	is_minus (char *str, char *nd)
{
	int first = atoi(st);
	int second = atoi(nd);
	return(first-second);
}

int	is_power (char *str, char *nd)
{
	int first = atoi(st);
	int second = atoi(nd);
	return(first*second);
}

int	is_div (char *str, char *nd)
{
	int first = atoi(st);
	int second = atoi(nd);
	return(first/second);
}

int	is_rest (char *str, char *nd)
{
	int first = atoi(st);
	int second = atoi(nd);
	return(first%second);
}

int	main (int argc, char **argv)
{
	int	r;

	if (argc == 4)
	{
		if (argv[2][0] == '+')
			r = is_add(argv[1],argv[3]);
		else if (argv[2][0] == '-')
			r = is_minus(argv[1],argv[3]);
		else if (argv[2][0] == '*')
			r = is_power(argv[1],argv[3]);
		else if (argv[2][0] == '/')
			r = is_div(argv[1],argv[3]);
		else if (argv[2][0] == '%')
			r = is_rest(argv[1],argv[3]);
		printf("%i\n", r);
	}
	else
		write(1,"\n",1);
	return(0);
}
