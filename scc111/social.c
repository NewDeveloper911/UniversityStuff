#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "miniset.h"

int is_reflexive(int set[])
{
    return FALSE;
}

int is_symmetric(int set[])
{
    return FALSE;
}

int is_transitive(int set[])
{
    return FALSE;
}

int main()
{
    int set[10];

    init_set(set);

    add_to_set(set, 1, 1);

    print_set(set);

    printf("in_set(1,1) = %d\n", in_set(set, 1, 1));

    return EXIT_SUCCESS;
}