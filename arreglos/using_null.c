#include <stdio.h>
#include <string.h>
int main ()
{
  char str[] = "computerhope \0'\0'0\n";
  printf("As a string:\n");
  printf("%s\n",str);
  printf("As an array of characters (character, decimal value of character):\n");
  printf("'%c' %d\n",str[0],str[0]);
  printf("'%c' %d\n",str[1],str[1]);
  printf("'%c' %d\n",str[2],str[2]);
  printf("'%c' %d\n",str[3],str[3]);
  printf("'%c' %d\n",str[4],str[4]);
  printf("'%c' %d\n",str[5],str[5]);
  printf("'%c' %d\n",str[6],str[6]);
  printf("'%c' %d\n",str[7],str[7]);
  printf("'%c' %d\n",str[8],str[8]);
  printf("'%c' %d\n",str[9],str[9]);
  printf("'%c' %d\n",str[10],str[10]);
  printf("'%c' %d\n",str[11],str[11]);
  printf("'%c' %d\n",str[12],str[12]);
  printf("'%c' %d\n",str[14],str[14]);
  printf("'%c' %d\n",str[15],str[15]);
  printf("'%c' %d\n",str[16],str[16]);
  printf("'%c' %d\n",str[17],str[17]);
  printf("'%c' %d\n",str[18],str[18]);
  printf("'%c' %d\n",str[19],str[19]);
  printf("'%c' %d\n",str[20],str[20]);
  return 0;
}