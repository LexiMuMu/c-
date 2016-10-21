/************************************************************
*      Filename: sort.h                                     *
*      Login: lm890                                         *
*      lab No: assignment 2                                 *
*      File Description: Qivot quick sort function and      *
*      define general type T                                *
*      Date Last Modified: 24/4/2015                        *
************************************************************/


#ifndef SORT_H_
#define SORT_H_

#ifdef MOVEMENT
#include "movement.h"
typedef Move T;
#else
typedef int T;
#endif

void dpqsort(T array[], const int size, int &ncomp, int &nswap);
#endif
