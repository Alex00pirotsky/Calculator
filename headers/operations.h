//
// Created by zeus on 22.06.2020.
//

#ifndef CALCULATOR_OPERATIONS_H
#define CALCULATOR_OPERATIONS_H

#include <unistd.h>
typedef struct s_op
{
    char *val;
}t_op;

typedef struct cl_op
{
    char *sign;
    int (*f)(int , int);
}do_op;



int divi    (int a , int b);
int module  (int a , int b);
int sum     (int a , int b);
int minus   (int a , int b);
int multi   (int a , int b);



#endif //CALCULATOR_OPERATIONS_H
