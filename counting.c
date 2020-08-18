//
// Created by zeus on 24.06.2020.
//

#include "counting.h"
#include <stdio.h>


do_op operat[] =
        {
                {"-", &minus },
                {"+", &sum   },
                {"*", &multi },
                {"/", &divi  },
                {"%", &module}
        };


int         ft_atoi     (char *s)
{
    int     res;
    int     neg;

    res     = 0;
    neg     = (*s == '-') ? -1 : 1;
    while (*s && *s != ' ')
    {
        (*s >= '0' && *s <= '9') ?
        res *= 10, res += *s - 48 : 0;
        s++;
    }
    return (res * neg);
}

char        *rev_str    (char const *str)
{
    int i;
    int j;
    char *re_str;

    i      = 0;
    j      = ft_str_len(str) - 1;
    re_str = (char *)malloc(sizeof(char) * j + 1);

    while (j >= 0)
        re_str[i++] = str[j--];

    re_str[i] = '\0';
    return re_str;
}

void ft_put_nbr(int a, char *cargo)
{
    if (a > 0)
    {
        ft_put_nbr(a / 10, cargo);
        cargo[ft_str_len(cargo)] =  (a % 10) + '0';
    }
}
char        *abr_atoi   (int val)
{
    char *str;
    int     i;
    int   neg;

    str     = (char *)malloc   (10); //just for first char and some other staff
    i       = 0;
    neg     = 0;
    (val < 0) ? neg = 1, val *= -1 : 0;

    while (val > 9)
    {
        str[i+1] = malloc(2);
        str[i]   = (val % 10) + '0';
        val     /= 10;
        i++;
    }
    str[i]  = val + 48;
    (neg == 1) ? str[i+neg] = '-' : 0;
    str[i+neg+1] = '\0';
    str     = rev_str(str);
    return str;
}




char *in_t_ch(int val)
{
    char *root;

    if (val == -2147483648 || val == 2147483647)
        return (val < 0) ? "-2147483648" : "2147483647";

    root = malloc(sizeof(char) * 1024);

    (val < 0) ? *root = '-', val *= -1 : 0;
    (val > 0) ? ft_put_nbr(val,root) : 0 , *root = '0';

    return root;
}


int         get_val     (char **ar, t_op *may)
{
    char *str;
    int     i;

    may->val = (char *)malloc(sizeof(char) * ft_str_len(*ar));
    i        = 0;

    while (**ar && **ar == ' ')
        *(*ar+=1);
    if (!**ar)
        return 0;
    while (**ar && **ar != ' ')
    {
        may->val[i] = **ar;
        i++;
        *(*ar+=1);
    }
    return 1;
}
t_op    *create         (char *arg)
{
    t_op    *main;
    int     i;

    main    = (t_op *)malloc(sizeof(t_op) * ft_str_len(arg));
    i       = 0;

    while (get_val(&arg, &main[i]))
        i++;

    return main;
}
int         cheap_or_exp(char const *s)
{
    return (*s == '*' || *s == '/' || *s == '%');
}

int         find_sign   (char const *arg)
{
    int i;

    i       = 0;
    while (operat[i].sign[0] != arg[0] && operat[i+1].sign)
        i++;
    return i;
}
int         get_sign    (t_op *con)
{
    int i;

    i       = 1;

    while (con[i+2].val && cheap_or_exp(con[i].val) == 0 && con[4].val)
        i += 2;

    return (cheap_or_exp(con[i].val)) ? (i) : 1;
}

void ft_put_struct(t_op * jes)
{
    int i;

    i = 0;

    while (jes[i].val)
    {
        printf("%s", jes[i].val);
        i++;
    }
    printf("\n");
}
t_op        *cut_struct (t_op *lesly, int level, char *wh)
{
    t_op *tmp;
    int     i;
    int     j;

    tmp     = (t_op *)malloc(sizeof(t_op) * sizeof(lesly));
    i       = 0;
    j       = 0;

    if (level == 0 && !lesly[4].val)
    {
        tmp[0].val = wh;
        return      tmp;
    }
    while (lesly[j].val)
    {
        (j == level) ? j += 3, tmp[i].val = wh, i+=1 : 0;
        tmp[i].val = lesly[j].val;
        i++;
        j++;
    }
    tmp[i].val = NULL;

    return tmp;


}


char        *go_count_this(char *arg)
{
    int       i;
    int       j;
    int     res;
    t_op *lesly;

    lesly   = create(arg);

    while (lesly[1].val != NULL)
    {
        i       = get_sign(lesly);
        j       = find_sign(lesly[i].val);
        res     = operat[j].f(ft_atoi(lesly[i-1].val), ft_atoi(lesly[i+1].val));
        lesly   = cut_struct(lesly, i-1, abr_atoi(res));
    }

    return lesly[0].val;
}
