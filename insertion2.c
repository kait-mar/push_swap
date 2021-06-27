#include "push_swap.h"

t_sort	sort_core(t_sort s, t_swap p)
{
	s.i = 0;
	s.j = p.len_a - 1;
	s.check = 0;
	while ((s.i < p.len_a / 2 || s.j < p.len_a) || p.len_a == 1)
	{
		if (s.i < p.len_a / 2
			&& p.a[s.i] >= s.minn && p.a[s.i] <= s.const_chunk)
		{
			s.check = 1;
			break ;
		}
		else if (s.j < p.len_a
			&& p.a[s.j] >= s.minn && p.a[s.j] <= s.const_chunk)
		{
			s.check = 2;
			break ;
		}
		(s.i)++;
		(s.j)--;
	}
	return (s);
}

t_sort	initialize_sort(t_swap p)
{
	t_sort	s;

	s.chunks = p.len_a / 5;
	s.ch = s.chunks;
	s.len = s.chunks * 5;
	s.rest = p.len_a % 5;
	return (s);
}

t_swap	sort_100(t_swap p)
{
	t_sort	s;

	s = initialize_sort(p);
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
