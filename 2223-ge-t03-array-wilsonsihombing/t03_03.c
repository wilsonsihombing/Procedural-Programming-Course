// 12S22011 - Wilson Eksaudi Sihombing
// 12S22028 - Tennov Pakpahan

#include <stdio.h>

int main(int _argc, char **_argv) {
  int angkaterbesar,angkaterkecil,n, i, b;
  float rataterkecil, rataterbesar;

  angkaterkecil = 0;
  angkaterbesar = 0;

  
  scanf("%d", &n);
  int angka[n];
  float rataawal[n-1];

  for(int i=0; i<n ; i++){
    scanf("%d", &angka[i]);
    if(angka[i] < angkaterkecil){
      angkaterkecil = angka[i];

    }else if(angka[i] > angkaterbesar){
      angkaterbesar = angka[i];
    }else{
 
    }
  }
  i = 0;
  for (int b = 0; b < n-2; b++)
  {
    rataawal[b] =(double) (angka[i] + angka[i+1]) / 2;
    i = i + 1;
  }
  rataterkecil = rataawal[0];
  b = 1;
  for (int x = 0; x < n-3; x++)
  {
    if (rataterkecil > rataawal[b])
    {
      rataterkecil = rataawal[b];
      
    }
    b = b + 1;
  }

  i = 0;
  rataterbesar = rataawal[0];
  b = 1;

  for (int x = 0; x < n-3; x++)
  {
    if (rataterbesar > rataawal[b])
    {
      
    }
    else
    {
      rataterbesar = rataawal[b];
      
    }
    b = b + 1;
    
  }
  
  printf("%d\n", angkaterkecil);
  printf("%d\n", angkaterbesar);
  printf("%.2f\n", rataterkecil);
  printf("%.2f\n", rataterbesar);


  return 0;


}