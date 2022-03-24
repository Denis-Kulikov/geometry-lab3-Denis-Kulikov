StructCircle InputArg(char *figur_enter)
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

int FigurChecking(char *figur_enter, int length) 
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

StructCircle InputInfo()
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
    is_circle = FigurChecking(figur_enter, j);
    if (!is_circle) 
        return Circle;
    else 
        return Circle = InputArg(figur_enter);

    return Circle;
}

void arg_del(char* arg, int length)
{
    for (int element = 0; element < length; element++)
        arg[element] = '\0';
}

struct info fun_area_perimetr(StructCircle cir)
{
    struct info number;
    number.perimeter = 2 * M_PI * cir.radius;
    number.area = M_PI * cir.radius * cir.radius;

    return number;
}

int fun_check_intersection(StructCircle Acir, StructCircle Bcir)
{
    double temp,
            distance
            = (Acir.point[0] - Bcir.point[0]) * (Acir.point[0] - Bcir.point[0])
            + (Acir.point[1] - Bcir.point[1]) * (Acir.point[1] - Bcir.point[1]);
    temp = distance;
    if (temp != 0) {
        for (int iteration = 0; iteration < MAX_ITERATION; iteration++)
            distance = (distance + temp / distance) / 2;
    }

    if (distance <= Acir.radius + Bcir.radius) {
        return 1;
    }
    return 0;
}