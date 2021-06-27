#include "push_swap.h"

t_swap	push_big(t_swap p)
{
	int	c;

	while (p.len_b > 0)
	{
		c = max(p.b, p.len_b);
		if (which_part(p.b, c, p.len_b) == 1)
		{
			while (p.b[0] != c)
				p = rb(p);
		}
		else
		{
			while (p.b[0] != c)
				p = rrb(p);
		}
		p = pa(p);
	}
	return (p);
}

t_swap  sort_500(t_swap p)
{
    int i;
	int	j;
    int minn;
	int	check;
	int	chunks;
	int	rest;
	int	const_chunk;
	int	len;
	int	ch;

	chunks = p.len_a / 11;
	ch = chunks;
	len = chunks * 11;
	rest = p.len_a % 11;
	while (chunks <= len)
	{
		minn = min(p.a, p.len_a);
		const_chunk = construct_chunk(p, minn, ch);
		while (p.len_a != 0 && p.len_b < chunks)
		{
			i = 0;
			j = p.len_a - 1;
			check = 0;
			while ((i < p.len_a / 2 || j < p.len_a) || p.len_a == 1)
			{
				if (i < p.len_a / 2 && p.a[i] >= minn && p.a[i] <= const_chunk)
				{
					check = 1;
					break ;
				}
				else if (j < p.len_a && p.a[j] >= minn && p.a[j] <= const_chunk)
				{
					check = 2;
					break ;
				}
				i++;
				j--;
			}
			if (check == 1)
				p = push_to_b(p, p.a[i], check);
			else if (check == 2)
				p = push_to_b(p, p.a[j], check);
			else
				break ;
		}
		chunks += ch;
	}
	while (p.len_a > 0 && rest--)
		p = pb(p);
	p = push_big(p);
	return (p);
}
