#include <float.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    printf("isnan(NAN)         = %d\n", isnan(NAN));
    printf("isnan(INFINITY)    = %d\n", isnan(INFINITY));
    printf("isnan(0.0)         = %d\n", isnan(0.0));
    printf("isnan(DBL_MIN/2.0) = %d\n", isnan(DBL_MIN / 2.0));
    printf("isnan(0.0 / 0.0)   = %d\n", isnan(0.0 / 0.0));
    printf("isnan(Inf - Inf)   = %d\n", isnan(INFINITY - INFINITY));
}