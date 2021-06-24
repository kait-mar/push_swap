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
	p.len_b = 0;
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
	printf("=======> %d actions\n", count);
}

t_swap	first_5elements(t_swap p)
{
	while (p.len_b > 0)
	{
		if (p.a[0] > p.b[0])
			p = pa(p);
		else if (p.len_b > 0 && p.b[0] > p.a[p.len_a - 1])
		{
			p = rra(p);
			p = pa(p);
			p = sa(p);
			p = ra(p);
			p = ra(p);
		}
		else if (p.b[0] > p.a[0] && p.b[0] < p.a[1])
		{
			p = pa(p);
			p = sa(p);
		}
		else if (p.len_a == 4 && p.b[0] > p.a[1] && p.b[0] < p.a[2])
		{
			p = pa(p);
			p = sa(p);
			p = ra(p);
			p = sa(p);
			p = rra(p);
		}
		else if (p.len_b > 0)
		{
			/*p = pb(p);
			p = sb(p);
			if (p.a[0] > p.b[0])
				p = pb(p);
			else if (p.b[0] < p.a[1])
			{
				p = pb(p);
				p = sa(p);
			}
			else
			{
				p = pa(p);
				p = rra(p);
				p = sa(p);
				p = ra(p);
				p = ra(p);
			}
			p = pa(p);*/
			p = pa(p);
			p = rra(p);
			p = sa(p);
			if (p.a[0] < p.a[p.len_a - 1])
			{
				//printf ("here==");
				//print_arguments(p);
				p = rra(p);
				p = sa(p);
				p = ra(p);
				p = ra(p);
				p = ra(p);
				//print_arguments(p);
			}
			else
			{
				//p = sa(p);
				p = ra(p);
				p = ra(p);
			}
		}
	}
	return (p);
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


int	main(int argc, char **argv)
{
	t_swap	p;

	count = 0;
	if (argc < 1)
		return (0);
	p = parse_arguments(argc, argv);
	print_arguments(p);
	if (p.len_a == 0)
		return (1);
	p = pb(p);
	p =pb(p);
	if (p.len_a <= 3)
		p = swap_3elements_a(p);
	else if (p.len_a <= 5)
		p = sort_insertion(p);
	else if (p.len_a <= 100)
		p = sort_100(p);
	print_arguments(p);
	return (1);
}

/*
int	main()
{
	t_swap	p;

	int	argc = 7;
	char *argv[8] = {"push", "52", "-96", "-9", "0", "98", "53", NULL};
	count = 0;
	if (argc < 1)
		return (0);
	p = parse_arguments(argc, argv);
	print_arguments(p);
	printf("=====================\n");
	if (p.len_a == 0)
		return (1);
	if (p.len_a <= 3)
		p = swap_3elements_a(p);
	else if (p.len_a <= 5)
		p = swap_5elements(p);
	else if (p.len_a <= 100)
		p = sort_100(p);
	print_arguments(p);
	return (1);
}
*/