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

t_sort	initialize_sort11(t_swap p)
{
	t_sort	s;

	s.chunks = p.len_a / 11;
	s.ch = s.chunks;
	s.len = s.chunks * 11;
	s.rest = p.len_a % 11;
	return (s);
}

t_swap	sort_500(t_swap p)
{
	t_sort	s;

	s = initialize_sort11(p);
	while (s.chunks <= s.len)
	{
		s.minn = min(p.a, p.len_a);
		s.const_chunk = construct_chunk(p, s.minn, s.ch);
		while (p.len_a != 0 && p.len_b < s.chunks)
		{
			s = sort_core(s, p);
			if (s.check == 1)
				p = push_to_b(p, p.a[s.i], s.check);
			else if (s.check == 2)
				p = push_to_b(p, p.a[s.j], s.check);
			else
				break ;
		}
		s.chunks += s.ch;
	}
	while (p.len_a > 0 && (s.rest)--)
		p = pb(p);
	p = push_big(p);
	return (p);
}
