#include "function.h"

int figur_checking(char *figur_enter) 
{
    char temp_str[L_CIRCLE + 1], figur_circle[] = "circle";
    if (figur_enter[L_CIRCLE] != '(') {
        if (figur_enter[L_CIRCLE] == ' ' || figur_enter[L_CIRCLE] == '\n') {
            for (int i = 0; i < L_CIRCLE; i++)
                printf(" ");
            printf("^ Ожидаются токены \"(x, y, r)\"\n");
        } else {
            printf("Фигура не распознана. Ожидается \"%s\"\n", figur_circle);
        }
        return 0;
    }
    for (int i = 0; i < L_CIRCLE; i++)
        temp_str[i] = tolower(figur_enter[i]);
    temp_str[L_CIRCLE] = '\0';
    return !strcmp(temp_str, figur_circle);
}