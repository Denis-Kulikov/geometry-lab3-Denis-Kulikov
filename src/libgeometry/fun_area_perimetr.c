#include "function.h"
#include "geometry.h"

struct info fun_area_perimetr(StructCircle cir)
{
    struct info number;
    number.perimeter = 2 * M_PI * cir.radius;
    number.area = M_PI * cir.radius * cir.radius;

    return number;
}