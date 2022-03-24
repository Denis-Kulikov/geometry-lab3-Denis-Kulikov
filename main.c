#include "geometry.h"
#include "geometry.c"

int main()
{
    int i, j, num;
    StructCircle circle_pos[N];
    struct info area_perimetr[N];

    printf("Уровень: Easy\nПравило ввода данных: тип(координата X, координата "
           "Y, радиус)\nПример: circle(1, 2, 3)\nОдна фигура занимает ровно "
           "одну строку\n"
           "Чтобы завершить ввод нажмите ещё раз enter после ввода данных\n\n");

    int info_intersection[N][N];
    for (int first_figur = 0; first_figur < N; first_figur++) {
        for (int second_figur = 0; second_figur < N; second_figur++) {
            info_intersection[first_figur][second_figur] = 0;
        }
    }

    for (i = 0; i < N; i++) {
        circle_pos[i] = InputInfo();
        if (circle_pos[i].radius == -2) {
            num = i;
            break;
        }
        if (circle_pos[i].radius == -1)
            i--;
    }

    for (i = 0; i < num; i++) {
        for (j = 0; j < num; j++) {
            if (i == j) {
                j++;
                if (j == num)
                    break;
            }
            info_intersection[i][j]
                    = fun_check_intersection(circle_pos[i], circle_pos[j]);
        }
    }

    for (i = 0; i < num; i++) {
        area_perimetr[i] = fun_area_perimetr(circle_pos[i]);
    }

    for (i = 0; i < num; i++) {
        printf("%d. circle(%.2f %.2f %.2f)\n\tperimeter = %.3f\n\tarea = "
               "%.3f\n\tintersects:\n",
               i + 1,
               circle_pos[i].point[0],
               circle_pos[i].point[1],
               circle_pos[i].radius,
               area_perimetr[i].perimeter,
               area_perimetr[i].area);
        for (j = 0; j < num; j++) {
            if (i == j) {
                j++;
                if (j == num)
                    break;
            }
            if (info_intersection[i][j] == 1)
                printf("\t   %d. circle\n", j + 1);
        }
        printf("\n");
    }
    return 0;
}
