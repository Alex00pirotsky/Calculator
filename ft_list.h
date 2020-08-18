//
// Created by zeus on 22.06.2020.
//

#ifndef CALCULATOR_FT_LIST_H
#define CALCULATOR_FT_LIST_H

#include <stdlib.h>


typedef struct s_list
{
    void          *data;
    struct s_list *next;
}                 t_list;


t_list  *arg_to_list (               char **argv);
t_list  *creat_el    (                void *data);

void    revers       (t_list **begin            );
void    append       (t_list **begin, void *data);
void    push         (t_list **begin, void *data);
void    pop          (t_list **begin            );
void ft_pr_lis(t_list *jes);


#endif //CALCULATOR_FT_LIST_H
