//
// Created by zeus on 22.06.2020.
//

#include "ft_list.h"
#include <stdio.h> ///todo




void ft_pr_lis(t_list *jes)
{
    t_list *tmp;

    tmp = jes;
    while (tmp)
    {
        printf("%s\n", tmp->data);
        tmp = tmp->next;
    }
}

t_list	*creat_el(void *data)
{
    t_list *tmp;

    tmp       = (t_list*)malloc(sizeof(t_list) + 2);
    tmp->data = data;
    tmp->next = NULL;
    return (tmp);
}

void    append(t_list **begin_list, void *data)
{
    t_list *tmp;

    tmp       = *begin_list;
    if (*begin_list == NULL)
    {
        *begin_list = creat_el(data);
        return;
    }
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = creat_el(data);
}

void    push(t_list **begin, void *data)
{
    t_list *tmp;
    tmp       = creat_el(data);
    tmp->next = *begin;
    *begin    = tmp;
}
void    pop(t_list **begin)
{
    t_list *tmp;

    tmp       = (*begin)->next;
    *begin    = tmp;
}



t_list  *arg_to_list(char **argv)
{
    int       i;
    t_list    *tmp;

    i         = 1;
    while (argv[i])
    {
        push(&tmp, argv[i]);
        i++;
    }
    return (tmp);
}
void revers(t_list **begin)
{
    t_list *tmp;
    tmp = NULL;
    while (*begin)
    {
        push(&tmp, (*begin)->data);
        *begin = (*begin)->next;
    }
    *begin = tmp;

}








