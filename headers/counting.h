//
// Created by zeus on 24.06.2020.
//

#ifndef CALCULATOR_COUNTING_H
#define CALCULATOR_COUNTING_H

#include "operations.h"
#include "creatin_list_of_val.h"



char        *rev_str      (char const *str  );
char        *abr_atoi     (int  val         );
int         ft_atoi       (char         *s  );

int         get_val       (char **ar, t_op *may);
int         cheap_or_exp  (char const *s    );
int         find_sign     (char const *arg  );
int         get_sign      (t_op *con        );
t_op        *create       (char *arg        );
t_op        *cut_struct   (t_op *lesly, int level, char *wh);
char        *go_count_this(char *arg        );







#endif //CALCULATOR_COUNTING_H
