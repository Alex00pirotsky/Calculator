#include <stdio.h>
#include "operations.h"
#include "ft_list.h"
#include "creatin_list_of_val.h"
#include "counting.h"






int have_it(char *in ,char wh)
{
    while (*in)
    {
        if(*in == wh)
            return 1;
        in++;
    }
    return 0;
}

char    *conclusion(char *arg)
{
    t_list *beg;

    beg = create_kitty(arg);

    //printf("\n");

    while (beg->next)
    {
        printf("%s = ", (char *)beg->data);
        beg->data = go_count_this(beg->data);
        printf("%s\n", beg->data);

        printf("%s | (x = %s)\n", (char *)beg->next->data, (char *)beg->data);
        (beg->next->data) ? beg->next->data = change_to(beg->next->data, beg->data, 1, 'X') : 0;
        printf("%s\n\n", (char *)beg->next->data);
        beg = beg->next;
    }
    (have_it(beg->data, ' ') && !have_it(beg->data, '(')) ? beg->data = go_count_this(beg->data) : 0;
    (have_it(beg->data, '(')) ? beg->data = conclusion(beg->data) : 0;
    return beg->data;
}

int main(int argc, char **argv)
{
    //"2 + 1 * 2 * 3 + 1 + 1"
    //;
    char *str = "((3 * 3 + (123 + 1)) + 4 + 7 * 2) + (123 + 1) * 3 + (2 + 2)";
    printf("%s\n\n", argv[1]);


    char *j = conclusion(argv[1]);


    printf("\n%s\n", j);

    return 0;
}
//Ushio to Tora
//Danganronpa 3
// DXD
//Kizumonogatari
//he Rising Of The Shield Hero