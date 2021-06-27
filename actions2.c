#include "push_swap.h"

t_swap	ss(t_swap p)
{
	p = sa(p);
	return (sb(p));
}

t_swap	realloc_a2(t_swap p, int c)
{
	int	*a;
	int	i;
	int	j;

	a = malloc(sizeof(int) * (p.len_b + 1));
	i = 0;
	j = 0;
	a[i++] = c;
	while (j < p.len_b)
	{
		a[i++] = p.b[j++];
	}
	free(p.b);
	(p.len_b)++;
	p.b = a;
	return (p);
}

t_swap	realloc_b2(t_swap p)
{
	int	*b;
	int	i;
	int	j;

	i = 0;
	j = 1;
	b = malloc(sizeof(int) * (p.len_a - 1));
	while (j < p.len_a)
	{
		b[i++] = p.a[j++];
	}
	free(p.a);
	(p.len_a)--;
	p.a = b;
	return (p);
}

t_swap	pb(t_swap p)
{
	int	c;

	write(1, "pb\n", 3);
	if (p.len_a == 0)
		return (p);
	c = p.a[0];
	p = realloc_b2(p);
	p = realloc_a2(p, c);
	return (p);
}

t_swap	ra(t_swap p)
{
	int	c;
	int	i;

	i = 0;
	write(1, "ra\n", 3);
	c = p.a[0];
	while (i < p.len_a - 1)
	{
		p.a[i] = p.a[i + 1];
		i++;
	}
	p.a[i] = c;
	return (p);
}
