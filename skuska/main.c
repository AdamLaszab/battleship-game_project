#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



void zmenEndian(unsigned long long* adresa) {
    unsigned char* p = (unsigned char*)adresa;  // Pretypovanie smerníka adresa na unsigned char*
    unsigned char temp;

    // Vymena bajtov pomocou troch prehodeni
    temp = p[0];
    p[0] = p[7];
    p[7] = temp;

    temp = p[1];
    p[1] = p[6];
    p[6] = temp;

    temp = p[2];
    p[2] = p[5];
    p[5] = temp;

    temp = p[3];
    p[3] = p[4];
    p[4] = temp;
}

int main() {
    unsigned long long num = 0x0102030405060708ull;

    printf("Pred zmenou endianu: 0x%016llx\n", num);

    zmenEndian(&num);

    printf("Po zmene endianu:    0x%016llx\n", num);

    return 0;
}