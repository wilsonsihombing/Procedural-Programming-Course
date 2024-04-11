// 12S22011 - Wilson Eksaudi Sihombing
// 12S22028 - Tennov Pakpahan

#include <stdio.h>

int main(int _argc, char **_argv) {
  int angkaterbesar,angkaterkecil,n;


  angkaterkecil = 0;
  angkaterbesar = 0;

  scanf("%d", &n); 
  int angka[n];

 
  for(int i=0; i<n ; i++){ 
    scanf("%d", &angka[i]);
    if(angka[i] < angkaterkecil){
      angkaterkecil = angka[i];
 
    }else if(angka[i] > angkaterbesar){
      angkaterbesar = angka[i];
    }else{

    }
  }
  printf("%d\n", angkaterkecil);
  printf("%d\n", angkaterbesar);


  return 0;

  
}
  

 

