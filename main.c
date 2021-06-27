#include "push_swap.h"

t_swap	first_5elements(t_swap p)
{
	while (p.len_b > 0)
	{
		if (p.a[0] > p.b[0])
			p = pa(p);
		else if (p.len_b > 0 && p.b[0] > p.a[p.len_a - 1])
			p = first_51(p);
		else if (p.b[0] > p.a[0] && p.b[0] < p.a[1])
		{
			p = pa(p);
			p = sa(p);
		}
		else if (p.len_a == 4 && p.b[0] > p.a[1] && p.b[0] < p.a[2])
			p = first_52(p);
		else if (p.len_b > 0)
			p = first_53(p);
	}
	return (p);
}

int	main(int argc, char **argv)
{
	t_swap	p;

	if (argc < 1)
		return (0);
	p = parse_arguments(argc, argv);
	if (p.len_a == 0)
		return (1);
	if (p.len_a <= 3)
		p = swap_3elements_a(p);
	else if (p.len_a <= 5)
		p = sort_insertion(p);
	else if (p.len_a <= 100)
		p = sort_100(p);
	else if (p.len_a <= 500)
		p = sort_500(p);
	return (1);
}
