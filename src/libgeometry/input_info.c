#include "function.h"
#include "libgeometry/geometry.h"

StructCircle input_info()
{
    StructCircle Circle = {{0, 0}, -1};
    char figur_enter[L_MAX], symbol, answer;
    int is_circle, j;
    
    for (j = 0; j < L_MAX; j++) {
        symbol = getchar();
        figur_enter[j] = symbol;
        if (symbol == '\n') {
            if (j == 0) {
                printf("Хотите закончить ввод данных? y/n \n");
                answer = getchar();
                answer = tolower(answer);
                if (answer != 'y' && answer != 'n')
                    while (getchar() != '\n');
                if (answer == 'y') {
                    printf("Конец ввода.\n\n");
                    Circle.radius = -2;
                    return Circle;
                } else {
                    getchar();
                    return Circle;
                }
            }
            break;
        }
    }
    is_circle = figur_checking(figur_enter);
    if (!is_circle) 
        return Circle;
    else 
        return Circle = input_arg(figur_enter);

    return Circle;
}