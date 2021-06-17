#include "push_swap.h"

void	print_error(t_swap p)
{
	write(2, "Error\n", 6);
	free(p.a);
	free(p.b);
	exit(EXIT_FAILURE);
}

t_swap	parse_arguments(int argc, char **argv)
{
	t_swap p;
	int	i;

	p.a = malloc(sizeof(int) * (argc - 1));
	p.b = malloc(sizeof(int) * (argc - 1));
	i = 0;
	while (argv[i + 1])
	{
		if (!valid(argv[i + 1]))
			print_error(p);
		p.a[i] = no_dup(p, argv[i + 1], i);
		i++;
	}
	return (p);
}

int	no_dup(t_swap p, char *arg, int i)
{
	int	res;

	res = ft_atoi(argv);
	while (i--)
	{
		if (res = argv[i])
			print_error(p);
	}
	return (res);
}

int	valid(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!(argv[i] == '-' || (argv[i] >= '0' && argv[i] <= '9')))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_swap	p;

	if (argc < 1)
		return (0);
	p = parse_arguments(argc, argv);
	return (1);
}