#pragma once

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

#define N 10 // максимальное количество фигур
#define COORDINATES_X_Y 2

int figur_checking(char*);
void arg_del(char*, int);
StructCircle input_arg(char*);
StructCircle input_info();
struct info fun_area_perimetr(StructCircle);
int fun_check_intersection(StructCircle, StructCircle);