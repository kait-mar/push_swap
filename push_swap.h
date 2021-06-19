#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "Libft/libft.h"

typedef struct s_swap
{
    int *a;
    int *b;
    int len_a;
    int len_b;
}           t_swap;

t_swap	parse_arguments(int argc, char **argv);
int	valid(char *arg);
void	print_error(t_swap p);
int     no_dup(t_swap p, char **arg, int i);
void	print_arguments(t_swap p);
t_swap  sa(t_swap p);
t_swap  sb(t_swap p);
t_swap  ss(t_swap p);
t_swap  realloc_b(t_swap p);
t_swap  realloc_a(t_swap p, int c);
t_swap  pa(t_swap p);
t_swap  realloc_a2(t_swap p, int c);
t_swap  realloc_b2(t_swap p);
t_swap  pb(t_swap p);
t_swap  ra(t_swap p);
t_swap  rb(t_swap p);
t_swap  rr(t_swap p);
t_swap  rra(t_swap p);
t_swap  rrb(t_swap p);
t_swap  rrr(t_swap p);


#endif