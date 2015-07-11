#include <math.h>
#include "haversine.h"

double dist(double r, double lat1, double long1, double lat2, double long2)
{
    return 2.0 * r *
        asin(sqrt
             (haversine(lat2 - lat1) +
              cos(lat1) * cos(lat2) * haversine(long2 - long1)));
}

long double lddist(long double r, long double lat1, long double long1,
                   long double lat2, long double long2)
{
    return 2.0 * r *
        asinl(sqrtl
              (ldhaversine(lat2 - lat1) +
               cosl(lat1) * cosl(lat2) * ldhaversine(long2 - long1)));
}
