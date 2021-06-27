#include "push_swap.h"

t_sort	sort_core(t_sort s, t_swap p)
{
	s.i = 0;
	s.j = p.len_a - 1;
	s.check = 0;
	while ((s.i < p.len_a / 2 || s.j < p.len_a) || p.len_a == 1)
	{
		if (s.i < p.len_a / 2 && p.a[s.i] >= s.minn && p.a[s.i] <= s.const_chunk)
		{
			s.check = 1;
			break ;
		}
		else if (s.j < p.len_a && p.a[s.j] >= s.minn && p.a[s.j] <= s.const_chunk)
		{
			s.check = 2;
			break ;
		}
		(s.i)++;
		(s.j)--;
	}
	return (s);
}

t_swap  sort_100(t_swap p)
{
	t_sort	s;
	int	chunks;
	int	rest;
	int	len;
	int	ch;

	chunks = p.len_a / 5;
	ch = chunks;
	len = chunks * 5;
	rest = p.len_a % 5;
	while (chunks <= len)
	{
		s.minn = min(p.a, p.len_a);
		s.const_chunk = construct_chunk(p, s.minn, ch);
		while (p.len_a != 0 && p.len_b < chunks)
		{
			/*s.i = 0;
			s.j = p.len_a - 1;
			s.check = 0;
			while ((s.i < p.len_a / 2 || s.j < p.len_a) || p.len_a == 1)
			{
				if (s.i < p.len_a / 2 && p.a[s.i] >= s.minn && p.a[s.i] <= s.const_chunk)
				{
					s.check = 1;
					break ;
				}
				else if (s.j < p.len_a && p.a[s.j] >= s.minn && p.a[s.j] <= s.const_chunk)
				{
					s.check = 2;
					break ;
				}
				(s.i)++;
				(s.j)--;
			}*/
			s = sort_core(s, p);
			if (s.check == 1)
				p = push_to_b(p, p.a[s.i], s.check);
			else if (s.check == 2)
				p = push_to_b(p, p.a[s.j], s.check);
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
