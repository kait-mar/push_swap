#include "push_swap.h"

int min(int *a, int len)
{
	int c;
	int i;

	i = 0;
	c = a[0];
	while (i < len)
	{
		if (c > a[i])
			c = a[i];
		i++;
	}
	return (c);
}

int max(int *a, int len)
{
	int c;
	int i;

	i = 0;
	c = a[0];
	while (i < len)
	{
		if (c < a[i])
			c = a[i];
		i++;
	}
	return (c);
}

t_swap  swap_3elements_a(t_swap p)
{
	if (p.a[0] == max(p.a, p.len_a))
	{
		p = ra(p);
		if (p.a[0] > p.a[1])
			p = sa(p);
	}
	else if (p.a[0] == min(p.a, p.len_a))
	{
		if (p.a[1] > p.a[2])
			p = ra(sa(p));
	}
	else
	{
		if (p.a[1] < p.a[2])
			p = sa(p);
		else
			p = rra(p);
	}
	return (p);
}

t_swap  swap_3elements_b(t_swap p)
{
	if (p.b[0] == max(p.b, p.len_b))
	{
		p = rb(p);
		if (p.b[0] > p.b[1])
			p = sb(p);
	}
	else if (p.b[0] == min(p.b, p.len_b))
	{
		if (p.b[1] > p.b[2])
			p = ra(sb(p));
	}
	else
	{
		if (p.b[1] < p.b[2])
			p = sb(p);
		else
			p = rb(p);
	}
	return (p);
}
