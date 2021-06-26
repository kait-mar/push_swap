#include "push_swap.h"

t_swap  push_big(t_swap p)
{
    int c;
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