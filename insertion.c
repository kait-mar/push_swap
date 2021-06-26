#include "push_swap.h"

int     which_part(int *a, int c, int len)
{
    int i;

    i = 0;
    while (i < len / 2)
    {
        if (a[i] == c)
            return (1);
        i++;
    }
    return (2);
}

t_swap  sort_insertion(t_swap p)
{
    int c;
    int i;

    i = 2;
    while (i-- && p.len_a > 3)
    {
        c = min(p.a, p.len_a);
        if (which_part(p.a, c, p.len_a) == 1)
        {
            while (p.a[0] != c)
                p = ra(p);
        }
        else
        {
            while (p.a[0] != c)
                p = rra(p);
        }
        p = pb(p);
    }
    p = swap_3elements_a(p);
    i = 2;
    while (i--)
        p = pa(p);
    return (p);
}

t_swap	push_to_b(t_swap p, int c, int check)
{
	if (check == 1)
	{
		while (p.a[0] != c)
			p = ra(p);
	}
	else if (check == 2)
	{
		while (p.a[0] != c)
			p = rra(p);
	}
	p = pb(p);
	return (p);
}

int	from_min(int *a, int len, int m)
{
	int c;
	int i;
	int	debug;

	i = 0;
	c = max(a, len);
	while (i < len)
	{
		debug = a[i];
		if (c >= a[i] && a[i] > m)
			c = a[i];
		i++;
	}
	return (c);
}

// this function returns the int to where we should stop searching about numbers in chunk
int	construct_chunk(t_swap p, int mine, int chunk)
{
	int	i;
	int	count;
	int	c;
	int	debug;

	count = 1;
	i = 0;
	c = mine;
	while (count <= chunk)
	{
		i = 0;
		while (i < p.len_a)
		{
			if (count == chunk)
				return (c);
			debug = p.a[i];
			if (p.a[i] == from_min(p.a, p.len_a, c))
			{
				count++;
				c = p.a[i];
			}
			i++;
		}
	}
	return (p.a[i]);
}

t_swap  sort_100(t_swap p)
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
	//int	debug;

	chunks = p.len_a / 5;
	ch = chunks;
	len = chunks * 5;
	rest = p.len_a % 5;
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
				//debug = p.a[i];
				//debug = p.a[j];
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
