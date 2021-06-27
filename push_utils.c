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
	t_swap	p;
	int		i;

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
	p.len_b = 0;
	return (p);
}

int	no_dup(t_swap p, char **arg, int i)
{
	int	res;

	if (ft_atoi(arg[i + 1]) > INT_MAX || ft_atoi(arg[i + 1]) < INT_MIN)
		print_error(p);
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
		if (!((argv[i] >= '0' && argv[i] <= '9')
			|| ((argv[i] == '-' || argv[i] == '+') && (argv[i + 1] >= '0' && argv[i + 1] <= '9')))
			|| ((argv[i] >= '0' && argv[i] <= '9') && (argv[i + 1] == '-' || argv[i + 1] == '+')))
			return (0);
		i++;
	}
	return (1);
}

t_swap	swap_5elements(t_swap p)
{
	int	i;

	i = 2;
	while (i--)
		p = pb(p);
	p = swap_3elements_a(p);;
	p = first_5elements(p);
	return (p);
}
