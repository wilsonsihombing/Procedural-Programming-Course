// 12S22011- Wilson Eksaudi Sihombing
// 12S22028 - Tennov Pakpahan

#include <stdio.h>

int main(int _argc, char **_argv)
{
    unsigned int x,y,z,operasi,total;

    scanf("%i", &x);
    scanf("%i", &y);
    scanf("%i", &z);

    operasi = x << y;
    total = operasi == z;


    printf("%i\n", operasi);
    printf("%i\n", total);
    

    


  return 0;
}
