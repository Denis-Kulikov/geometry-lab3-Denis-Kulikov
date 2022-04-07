#include "function.h"
#include "geometry.h"

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