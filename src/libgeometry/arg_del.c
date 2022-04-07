#include "function.h"

void arg_del(char* arg, int length)
{
    for (int element = 0; element < length; element++)
        arg[element] = '\0';
}