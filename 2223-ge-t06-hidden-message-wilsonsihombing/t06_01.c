// 12S22011 - Wilson Eksaudi Sihombing
// 12S22028 - Tennov Pakpahan

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longcount (char kata[]){
  int panjang;
  if (strlen(kata)> 98)
  {
    return panjang = strlen(kata);
  }else{
    return panjang = strlen(kata)-1;
  }

}

void wordprint (char kata[], int panjang, int x)
{
  int jarak = panjang/x;
  for(int i = 0; i < jarak + 1  ; i++)
  {
    for(int j = 0; j < x  ; j++)
    {
      int index = i * x + j;
      if (index < panjang)
      {
        printf("%c", kata[index]);
      }else
      { 
        printf("%c", '#');
      }
     
      
    } 
    printf("\n"); 
  }
}

void transposeprint (char kata[], int panjang, int x){
  int jarak = panjang/x;
  for(int i = 0; i < x; i++)
  {
    for(int j = 0; j < jarak + 1; j++)
    {
      int index = j * x + i;
      if (index < panjang)
      {
        printf("%c", kata[index]);
      }
      else
      {
        printf("%c", '#');
      } 
    } 
  }
  printf("\n"); 
  

}


int main(int argc, char *argv[]){
  int x;
  x = atoi(argv[1]);

  fflush(stdin);
  char kata[100];
  fgets(kata, 100, stdin);
  int panjang = longcount(kata);

  wordprint(kata, panjang, x);
  transposeprint (kata, panjang, x);

  return 0;

}
