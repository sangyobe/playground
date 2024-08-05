#include <immintrin.h>
#include <stdio.h>
#ifdef AVX_PERFORMANCE
#include <dtCore/src/dtUtils/dtTimeCheck.h>
using dt::Utils::TimeCheck;
#endif

// d = a * b + c
void multiply_and_add(const double *a, const double *b, const double *c, double *d)
{
    for (int i = 0; i < 4; i++)
    {
        d[i] = a[i] * b[i];
        d[i] = d[i] + c[i];
    }
}

// AVX2, _mm256_fmadd_ps
__m256d avx_multiply_and_add(__m256d a, __m256d b, __m256d c)
{
    return _mm256_fmadd_pd(a, b, c);
}

int main()
{
    __m256d a = _mm256_set_pd(1.0, 2.0, 3.0, 4.0);
    __m256d b = _mm256_set_pd(2.0, 2.0, 2.0, 2.0);
    __m256d c = _mm256_set_pd(1.0, 2.0, 3.0, 4.0);
    __m256d d = avx_multiply_and_add(a, b, c);

    for (int i = 0; i < 4; i++)
        printf("%f * %f + %f = %f\n", a[i], b[i], c[i], d[i]);

#ifdef AVX_PERFORMANCE
    TimeCheck tc;
    int loop_count = 10000;

    __m256d a2 = _mm256_set_pd(1.0, 2.0, 3.0, 4.0);
    __m256d b2 = _mm256_set_pd(2.0, 2.0, 2.0, 2.0);
    __m256d c2 = _mm256_set_pd(1.0, 2.0, 3.0, 4.0);

    tc.Start();
    for (int i = 0; i < loop_count; i++)
    {
        __m256d d = avx_multiply_and_add(a2, b2, c2);
    }
    tc.Stop();
    printf("%.6f usec elapsed for %d avx_multiply_and_add() calls.\n", tc.GetElapsedTime_msec(), loop_count);

    double a3[4]{1.0, 2.0, 3.0, 4.0};
    double b3[4]{1.0, 2.0, 3.0, 4.0};
    double c3[4]{1.0, 2.0, 3.0, 4.0};
    double d3[4];

    tc.Start();
    for (int i = 0; i < loop_count; i++)
    {
        multiply_and_add(a3, b3, c3, d3);
    }
    tc.Stop();
    printf("%.6f usec elapsed for %d multiply_and_add() calls.\n", tc.GetElapsedTime_msec(), loop_count);
#endif

    return 0;
}