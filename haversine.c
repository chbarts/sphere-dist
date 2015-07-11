#include <math.h>
#include "versine.h"

double haversine(double th)
{
    return 0.5 * versine(th);
}

long double ldhaversine(long double th)
{
    return 0.5 * ldversine(th);
}
