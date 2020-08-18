//
// Created by zeus on 22.06.2020.
//

#include "operations.h"




int     divi    (int a , int b)
{
    if (!b)
    {
        write(2,"DIVISION_ZERO\n",15);
        return (0);
    }
    return (a / b);
}
int     module  (int a , int b)
{
    if (!b)
    {
        write(2,"MODULE_ZERO\n",  13);
        return (0);
    }
    return (a % b);
}
int     sum     (int a , int b)
{
    return (a + b);
}

int     minus   (int a , int b)
{
    return (a - b);
}

int     multi   (int a , int b)
{
    return (a * b);
}



//void **make_dubl(int row, int col)
//{
//    void **me = (void **)malloc(sizeof(void *) * col);
//    while (col >= 0)
//    {
//        *me = (void *)malloc(sizeof(void) * row);
//        col--;
//    }
//        return me;
//}