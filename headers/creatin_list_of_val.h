//
// Created by zeus on 24.06.2020.
//

#ifndef CALCULATOR_CREATIN_LIST_OF_VAL_H
#define CALCULATOR_CREATIN_LIST_OF_VAL_H

#include "ft_list.h"

int         ft_str_len   (char          const       *str );
int         el_in_br     (char                      *argv);

char        *brek_block  (char                      *argv);
char    *marry(char **from, char *to, char opt);

char    *change_to(char *argv, char *opt, int clear, char wh);

void        brek_list    (t_list                  **begin);
void        complete_list(t_list **beg, char        *argv);
t_list      *create_kitty(char                      *argv);



#endif //CALCULATOR_CREATIN_LIST_OF_VAL_H
