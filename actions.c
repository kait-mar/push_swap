#include "push_swap.h"

t_swap  sa(t_swap p)
{
    int c;

    if (p.len_a < 2)
        return (p);
    c = p.a[0];
    p.a[0] = p.a[1];
    p.a[1] = c;
    return (p);
}

t_swap  sb(t_swap p)
{
    int c;

    if (p.len_b < 2)
        return (p);
    c = p.b[0];
    p.b[0] = p.b[1];
    p.b[1] = c;
    return (p);
}

t_swap  realloc_b(t_swap p)
{
    int *b;
    int i;

    i = 0;
    b = malloc(sizeof(int) * (p.len_b - 1));
    while (i < p.len_b)
    {
        b[i] = p.b[i + 1];
        i++;
    }
    free(p.b);
    (p.len_b)--;
    p.b = b;
    return (p);
}

t_swap  realloc_a(t_swap p, int c)
{
    int *a;
    int i;

    a = malloc(sizeof(int) * (p.len_a + 1));
    i = 0;
    a[i++] = c;
    while (i < p.len_a + 1)
    {
        a[i] = p.a[i - 1];
        i++;
    }
    free(p.a);
    (p.len_a)++;
    p.a = a;
    return (p);
}

t_swap  pa(t_swap p)
{
    int c;

    if (p.len_b == 0)
        return (p);
    c = p.b[0];
    p = realloc_b(p);
    p = realloc_a(p, c);
    return (p);
}