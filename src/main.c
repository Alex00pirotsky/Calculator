#include <stdio.h>
#include "../headers/operations.h"
#include "../headers/ft_list.h"
#include "../headers/creatin_list_of_val.h"
#include "../headers/counting.h"






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
char *add_space(char *ar)
{
    char *n_ar;
    int j;

    j = 0;
    n_ar = malloc(sizeof(char) * ft_str_len(ar) * 3);

    for (int i = 0; i < ft_str_len(ar); ++i)
    {
        if(ar[i] == '+' || ar[i] == '-' || ar[i] == '*' || ar[i] == '/')
        {
            if(i > 0 && ar[i - 1] != ' ')
            {
                n_ar[j] = ' ';
                j++;
            }
            if(ar[i + 1] != ' ')
            {
                n_ar[j] = ar[i];
                n_ar[j + 1] = ' ';
                j += 2;
                i++;
            }
        }
        n_ar[j] = ar[i];
        j++;
    }
    return n_ar;
}
int main(int argc, char **argv)
{
    printf("%s\n", argv[1]);
    if(argc != 2)
    {
    	printf("YOU should write only one arg");
	return 0;
    }
    char *j = add_space(argv[1]);

    j = conclusion(j);


    printf("%s\n", j);

    return 0;
}
//Ushio to Tora
//Danganronpa 3
// DXD
//Kizumonogatari
//he Rising Of The Shield Hero
