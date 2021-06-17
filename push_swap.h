#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include "Libft/libft.h"

typedef struct s_swap
{
    int *a;
    int *b;
}           t_swap;

t_swap	parse_arguments(int argc, char **argv);
int	valid(char *arg);
void	print_error(t_swap p);

#endif