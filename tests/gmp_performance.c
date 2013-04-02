#include <cmp.h>
#include <cmp_rand.h>
#include <gmp.h>
#include <stdio.h>

int main()
{
    mpz_t a_gmp, b_gmp, r_gmp;
    mpz_inits(a_gmp, b_gmp, r_gmp, NULL);

    uint64_t a[4];
    uint64_t b[4];
    uint64_t r[8];
    //char ahex[4*16 + 1];
    //char bhex[4*16 + 1];
    //char rhex[8*16 + 1];

    cmp_srand(1234);

    //cmp_uint64_get_hex(ahex, 4*16 + 1, a, 4);
    //cmp_uint64_get_hex(bhex, 4*16 + 1, b, 4);
    //cmp_uint64_get_hex(rhex, 8*16 + 1, r, 8);

    //printf("%s * %s = %s\n", ahex, bhex, rhex);
    uint64_t i = 0;
    for (; i < 10000000; i++) {
        cmp_uint64_rand(a, 4);
        cmp_uint64_rand(b, 4);
        mpz_import(a_gmp, 4, -1, 8, 0, 0, a);
        mpz_import(b_gmp, 4, -1, 8, 0, 0, b);
        mpz_mul(r_gmp, a_gmp, b_gmp);
        mpz_export(r, NULL, -1, 8, 0, 0, r_gmp);
    }
    return 0;
}
