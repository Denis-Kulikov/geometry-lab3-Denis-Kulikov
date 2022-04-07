#include "function.h"

StructCircle input_arg(char *figur_enter)
{
    StructCircle Circle = {{0, 0}, -1};
    int length, num = 0, arg = 0, space = 0, arg_coutn[] = {0, 0, 0},
        is_minus[] = {0, 0, 0}, is_dot[] = {0, 0, 0};
    char buffer[L_MAX], temp_arg[L_MAX];
    for (int i = 0; i < L_MAX; i++)
        buffer[i] = 0;
    for (int i = L_CIRCLE; i < L_MAX && figur_enter[i - 1] != '\n'; i++) {
        temp_arg[i - L_CIRCLE] = figur_enter[i];
        length = i - L_CIRCLE;
    }
    
    for (int i = 0; i <= length; i++) {
        if (temp_arg[0] != '(') {
           SPACE
            printf(" ^ Токены должны быть заключены в скобки\n");
            ERROR 
        }
        switch (temp_arg[i]) {
            case '(':
                if (i == 0)
                    break;
                SPACE
                printf(" ^ Указана лишняя скобка");
                if (arg != 2) 
                    printf(". Ожидается токен\n");
                else printf("\n");
                ERROR
                break;
            case ' ':
                space++;
                break;
            case '-':
                if ((is_minus[arg] || arg_coutn[arg]) && arg != 2) {
                    SPACE 
                    printf("^ неправильное использование минуса\n");
                    ERROR
                }
                if (arg == 2) {
                SPACE 
                printf("^ радиус не может быть отрицательным\n");
                ERROR
                }
                is_minus[arg]++;
                break;
            case '.':
                if (is_dot[arg]) {
                    SPACE 
                    printf("^ неправильное использование точки\n");
                    ERROR
                }
                buffer[num] = '.';
                num++;
                is_dot[arg]++;
                break;
            case ',':
                if (arg_coutn[arg]) {
                    buffer[num] = ' ';
                    num++;
                    arg++;
                    //printf("%s\n", buffer);
                    if (arg > 2) {
                        SPACE
                        printf("^ Лишний токен\n");
                        ERROR
                    }
                } else {
                    SPACE 
                    printf("^ Пустой токен\n");
                    ERROR
                }
                break;
            case ')':
                if  (temp_arg[i + 1] == '\n' && arg_coutn[2]) {
                char *YValue, *RadValue;
                Circle.point[0] = strtod(buffer, &YValue);
                if (is_minus[0])
                    Circle.point[0] *= -1;
                Circle.point[1] = strtod(YValue, &RadValue);
                if (is_minus[1])
                    Circle.point[1] *= -1;
                Circle.radius = strtod(RadValue, NULL);
                return Circle;
                } else if (temp_arg[i] == ')'  && arg_coutn[2]){
                    SPACE 
                    printf(" ^ Лишняя запись после токенов. На одной строке может быть только одна фигура\n");
                    ERROR
                } else {
                    SPACE 
                    printf(" ^ Указаны не все токены\n");
                    ERROR
                }
                break;
            default:
                if (isdigit(temp_arg[i])) {
                    arg_coutn[arg]++;
                    buffer[num] = temp_arg[i];
                    num++;
                    printf("%c", buffer[i]);
                } else if (temp_arg[i] == '\n') {
                    SPACE 
                    printf("^ Токены должны быть заключены в скобки\n");
                    ERROR
                } else {
                    SPACE
                    printf("i = %d val = %c\n", i, temp_arg[i]);
                    printf("^ неправильное введены токены\n");
                    ERROR
                }
                break;
        }
    }
    return Circle;
}