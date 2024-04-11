// 12S22011- Wilson Eksaudi Sihombing
// 12S22028 - Tennov Pakpahan
#include <stdio.h>

int main(int _argc, char **_argv)
{
  float num1,num2,num3,num4,num5,amount,mean;
  
  
  scanf("%f", &num1);
  scanf("%f", &num2);
  scanf("%f", &num3);
  scanf("%f", &num4);
  scanf("%f", &num5); 
  


  amount = num1 + num2 + num3 + num4 + num5;
  mean = amount/5;

  printf("%.3f\n", amount);
  printf("%.3f", mean);


  return 0;
}
