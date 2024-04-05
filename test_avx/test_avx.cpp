#include <immintrin.h>
#include <stdio.h>

// d = a * b + c
void multiply_and_add(const float* a, const float* b, const float* c, float* d)
{
    for (int i=0; i<8; i++) {
        d[i] = a[i] * b[i];
        d[i] = d[i] + c[i];
    }
}

// AVX2, _mm256_fmadd_ps
__m256 avx_multiply_and_add(__m256 a, __m256 b, __m256 c)
{
    return _mm256_fmadd_ps(a, b, c);
}

int main()
{
    return 0;
}