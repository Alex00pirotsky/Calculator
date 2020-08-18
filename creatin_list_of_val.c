//
// Created by zeus on 24.06.2020.
//

#include "creatin_list_of_val.h"
#include <stdio.h>

int     ft_str_len(char const *str)
{
    int     i;

    i = 0;
    while (str[i])
        i++;
    return     (i);
}


///COUNTING HOW MANY ELEMENT IN BRACKET
int     el_in_br(char *argv)
{
    int     j;
    int     i;

    i = 1;
    j = 0;

    while (*argv != '(' && *argv)
        argv++;
    //we really dont need all element which stey in front of breaket

    if (!*argv)
        return 0;
    //if there no breaket we will have null

    *(argv+=1);
    //argv stop when we found '(', so we should step over this elemen to go to next loop

    while (i > 0 && *argv)
    {
        j++;
        (*argv == ')') ? i-- : 0;
        (*argv == '(') ? i++ : 0;
        argv++;
    }
    //counting how many element from pair of break
    return     (j);
}
///BREAKING BLOCK OF BRACKET, I MEAN THAT I TAKING ALL ELEMENT IN BRACKET, AND CREATE STR.
char    *brek_block(char *argv)
{
    int     i;
    char    *str;

    str = (char *)malloc(sizeof(char) * ft_str_len(argv));
    i   = 0;

    while (*argv != '(' && *argv)
        argv++;
    //if we start for some reason not from breket we will go to there


    while (i < el_in_br(argv) - 1 && argv[i+1])
    {
        str[i] = argv[i+1];
        i++;
    }
    //becouse argv first is '(' we add always 1, and if loop condition we minus one
    //int this loop we create str from all elements in breaket what we need
    return     (str);
}
///HERE I MARRY TWO STR FROM->TO. OPT = STOP POINT(OPT = OPTION)
char    *marry(char **from, char *to, char opt)
{
    int i;

    i = ft_str_len(to);

    while (**from && **from != opt)
    {
        to[i] = **from;
        *(*from+=1);
        i++;
    }
    return     (to);

}


///HERE I CHANGE IN FROM VALUE WHICH START IN WH POINT , AND CLEAR RANGE BY INT_CLEAR
char    *change_to(char *arg, char *opt, int clear, char wh)
{
    char    *str;

    str = (char *)malloc(sizeof(char) * ft_str_len(arg));

    str = marry(&arg , str, wh);
    str = marry(&opt, str, 0);
    *(arg += clear);
    str = marry(&arg, str, 0);
    str[ft_str_len(str)] = '\0';

    return     (str);


}
///CHANGE BRACKET IN LIST TO X
void    brek_list(t_list **begin)
{
    t_list *tmp;

    tmp = *begin;

    while (tmp->next)
    {
        tmp->data = change_to(tmp->data, "X", el_in_br(tmp->data) + 1, '(');
        tmp       = tmp->next;
    }
}
///FIND EACH BRACKET AND APPEND IT ON NEXT LIST, SO THE LAST WILL BE WITHOUT BRACKET
void    complete_list(t_list **beg, char *argv)
{

    while (el_in_br(argv))
    {
        argv = brek_block(argv);
        append      (beg, argv);
    }
}
///CREATE LIST, APPEND ALL VALUE BRACKET, CHANGE TO X
///WHAT IN UP LEVEL, BECAME X ON THIS LEVEL
t_list  *create_kitty(char *argv)
{
    t_list *honey;

    honey = creat_el(argv        );
    complete_list   (&honey, argv);
    brek_list       (&honey      );
    revers          (&honey);

    return     (honey);

}

