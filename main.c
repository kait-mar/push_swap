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
		p.a[i] = no_dup(p, argv, i);
		i++;
	}
	p.len_a = argc - 1;
	return (p);
}

int	no_dup(t_swap p, char **arg, int i)
{
	int	res;

	res = ft_atoi(arg[i + 1]);
	while (i--)
	{
		if (res == p.a[i])
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

void	print_arguments(t_swap p)
{
	int	i;

	i = 0;
	while (i < p.len_a)
	{
		printf("%d\n", p.a[i++]);
	}
	printf("***************\n");
	i = 0;
	while (i < p.len_b)
	{
		printf("%d\n", p.b[i++]);
	}
}

int	main(int argc, char **argv)
{
	t_swap	p;

	if (argc < 1)
		return (0);
	p = parse_arguments(argc, argv);
	p = rra(p);
	p = pb(p);
	print_arguments(p);
	return (1);
}
