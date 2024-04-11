// 12S22011 - Wilson Eksaudi Sihombing
// 12S22028 - Tennov Pakpahan

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
  int x;
  x = atoi(argv[1]);

  fflush(stdin);
  char kata[100];
  fgets(kata, 100, stdin);
  int panjang;
  if (strlen(kata) > 98)
  {
    panjang = strlen(kata); 
  }
  else
  {
    panjang = strlen(kata)-1; 
  }
  
  int jarak = (panjang/x);
  
  

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
  
  
  return 0;
}
