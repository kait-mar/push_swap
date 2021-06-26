#include "push_swap.h"

t_swap  rb(t_swap p)
{
    int c;
    int i;

    count++;
     printf("rb\n");
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

t_swap  rr(t_swap p)
{
    count++;
    p = ra(p);
    p = rb(p);
    return (p);
}

t_swap  rra(t_swap p)
{
    int i;
    int *a;

    if (p.len_a == 0)
        return (p);
     printf("rra\n");
    count++;
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

t_swap  rrb(t_swap p)
{
    int i;
    int *a;

    if (p.len_b == 0)
        return (p);
    count++;
     printf("rrb\n");
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

t_swap  rrr(t_swap p)
{
    count++;
    p = rra(p);
    p = rrb(p);
    return (p);
}
