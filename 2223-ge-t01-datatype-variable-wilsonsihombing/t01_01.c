// 12S22011- Wilson Eksaudi Sihombing
// 12S22028 - Tennov Pakpahan

#include <stdio.h>

int main(int _argc, char **_argv)
{
  int number;
  char ascii;
  int boolean;
  unsigned int nonnum;
  float fraction;

  scanf("%d", &number);
  scanf(" %c", &ascii);
  scanf("%i", &boolean);
  scanf("%i", &nonnum);
  scanf("%f", &fraction);

  printf("%d\n", number); 
  printf("%c\n", ascii);
  printf("%i\n", boolean);
  printf("%i\n", nonnum);
  printf("%.2f\n", fraction);


  return 0;
}
