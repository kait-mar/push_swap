#include "push_swap.h"

t_swap	rb(t_swap p)
{
	int	c;
	int	i;

	write(1, "rb\n", 3);
	i = 0;
	c = p.b[0];
	while (i < p.len_b - 1)
	{
		p.b[i] = p.b[i + 1];
		i++;
	}
	p.b[i] = c;
	return (p);
}

t_swap	rr(t_swap p)
{
	p = ra(p);
	p = rb(p);
	return (p);
}

t_swap	rra(t_swap p)
{
	int	i;
	int	*a;

	if (p.len_a == 0)
		return (p);
	write(1, "rra\n", 4);
	i = 1;
	a = malloc(sizeof(int) * p.len_a);
	while (i < p.len_a)
	{
		a[i] = p.a[i - 1];
		i++;
	}
	a[0] = p.a[p.len_a - 1];
	free(p.a);
	p.a = a;
	return (p);
}

t_swap	rrb(t_swap p)
{
	int	i;
	int	*a;

	if (p.len_b == 0)
		return (p);
	write(1, "rrb\n", 4);
	i = 1;
	a = malloc(sizeof(int) * p.len_b);
	while (i < p.len_b)
	{
		a[i] = p.b[i - 1];
		i++;
	}
	a[0] = p.b[p.len_b - 1];
	free(p.b);
	p.b = a;
	return (p);
}

t_swap	rrr(t_swap p)
{
	p = rra(p);
	p = rrb(p);
	return (p);
}
