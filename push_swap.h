#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "Libft/libft.h"
#define INT_MAX 2147483647
#define INT_MIN -2147483648

typedef struct s_swap
{
    int *a;
    int *b;
    int len_a;
    int len_b;
}           t_swap;

typedef struct s_sort
{
    int minn;
    int check;
    int chuncks;
    int	rest;
    int	j;
    int i;
    int	const_chunk;
}       t_sort;

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
t_swap  swap_3elements_a(t_swap p);
int max(int *a, int len);
int min(int *a, int len);
t_swap  swap_3elements_b(t_swap p);
t_swap	first_5elements(t_swap p);
int     which_part(int *a, int c, int len);
t_swap  sort_insertion(t_swap p);
int     how_many_moves(int c, t_swap p);
t_swap	push_to_b(t_swap p, int c, int check);
int	from_min(int *a, int len, int m);
t_swap  sort_100(t_swap p);
int	construct_chunk(t_swap p, int mine, int chunk);
t_swap  push_big(t_swap p); 
t_swap  sort_500(t_swap p);
t_sort	sort_core(t_sort s, t_swap p);

#endif