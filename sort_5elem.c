#include "push_swap.h"

t_swap	first_51(t_swap p)
{
	p = rra(p);
	p = pa(p);
	p = sa(p);
	p = ra(p);
	p = ra(p);
	return (p);
}

t_swap	first_52(t_swap p)
{
	p = pa(p);
	p = sa(p);
	p = ra(p);
	p = sa(p);
	p = rra(p);
	return (p);
}

t_swap	first_53(t_swap p)
{
	p = pa(p);
	p = rra(p);
	p = sa(p);
	if (p.a[0] < p.a[p.len_a - 1])
	{
		p = rra(p);
		p = sa(p);
		p = ra(p);
		p = ra(p);
		p = ra(p);
	}
	else
	{
		p = ra(p);
		p = ra(p);
	}
	return (p);
}
