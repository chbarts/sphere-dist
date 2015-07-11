#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <errno.h>
#include <math.h>
#include "dist.h"

static int read_ld(char *str, long double *res)
{
    char *endptr = NULL;

    if (((*res = strtold(str, &endptr)) == 0.0) && (endptr == str)) {
        return -1;
    }

    if (ERANGE == errno) {
        if (HUGE_VALL == *res) {
            return -2;
        } else if (-HUGE_VALL == *res) {
            return -3;
        } else {
            return -4;
        }
    }

    return 0;
}

#define get_ld(str, num) do { switch (read_ld(str, &num)) {     \
case 0: break; \
case -1: fprintf(stderr, "%s: %s invalid input\n", argv[0], str); goto num ## end; \
case -2: fprintf(stderr, "%s: %s caused positive overflow\n", argv[0], str); goto num ## end; \
case -3: fprintf(stderr, "%s: %s caused negative overflow\n", argv[0], str); goto num ## end; \
case -4: fprintf(stderr, "%s: %s caused underflow\n", argv[0], str); goto num ## end; \
      num ## end: exit(EXIT_FAILURE); } } while (0)

int main(int argc, char *argv[])
{
    long double radius, lat1, long1, lat2, long2;

    if (argc != 6) {
        puts("distance radius lat1 long1 lat2 long2");
        return 0;
    }

    get_ld(argv[1], radius);
    get_ld(argv[2], lat1);
    get_ld(argv[3], long1);
    get_ld(argv[4], lat2);
    get_ld(argv[5], long2);

    printf("%.*Lg\n", LDBL_DIG, lddist(radius, lat1, long1, lat2, long2));

    return 0;
}
