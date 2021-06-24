t_swap	two_hold(t_swap p)
{
	int	i;
	int	j;
	int	c1;
	int	c2;

	while (i < p.len_a / 2 && j < p.len_a)
	{
		if (p.a[i] != c1)
			i++;
		if (p.a[j] != c2)
			j++;
		if (p.a[i] == c1 && p.a[j] == c2)
			break ;
	}
}

int	how_many_moves(int c, t_swap p)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (i < p.len_a)
    {
        if (p.a[i] == c)
            break ;
        i++;
    }
    if (i < p.len_a / 2)
    {
        i = 0;
        while (p.a[0] != c)
        {
            p = ra(p);
            count++;
        }
    }
    else
    {
        i = p.len_a - 1;
        while (p.a[0] != c)
        {
            p = rra(p);
            count++;
        }
    }
    return (count);
}
