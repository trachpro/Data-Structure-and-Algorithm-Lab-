#include <stdio.h>


void Encrypt(FILE *fin, int n, char s[]){
  int c;
  int i = 0;
  
  while ( (c = fgetc(fin)) != EOF) {
    s[i] = c;
    
    if (s[i] >= 'a' && s[i]<= 'z') {
      s[i] = (c - 'a' + n) % 26 + 'a';
     
    }

    else if( s[i] >= 'A' && s[i] <= 'Z'){
      s[i] = ( c - 'A' + n) % 26 + 'A';
     
    }
    /* fputc(s[i],fin);*/
    putchar(s[i]);
    i++;
    
  }
  fprintf(fin,"\n%s\n","Encrypt");
   fprintf(fin,"\n%s\n",s);
  
}



void Decrypt(FILE *fin, int n, char s[], char s1[]){
  int i = 0;
  while (s[i] != '\0') {
    s1[i] = s[i];

    if (s1[i] >= 'a' && s1[i] <= 'z') {
      s1[i] = (s[i] - 'a' - n + 26) % 26 + 'a'; 
    }

    if (s1[i] >= 'A' && s1[i] <= 'Z') {
      s1[i] = ( s[i] - 'A' - n + 26) % 26 + 'A';
    }
    putchar(s1[i]);
    i++;
  }
  fprintf(fin,"\n%s\n","Decrypt");
  fprintf(fin,"\n%s\n",s1);
}



int main(int argc, char *argv[])
{
  FILE *f1;
  int step;
  char s[100000];
  char s1[100000];

  f1 = fopen(argv[1],"a+");

  printf("Syntax: <filename> step\n");

  if (argc != 3) {
    printf("Wrong syntax\n");
    return -1;
  }
  
  if (f1 == NULL) {
    printf("Cannot open file\n");
    return -1;
  }

  if (sscanf(argv[2],"%d",&step) != 1) {
    printf("Wrong syntax\n");
    return -1;
  }

  sscanf(argv[2],"%d",&step);


  Encrypt(f1,step,s);

  Decrypt(f1,step,s,s1);
  fclose(f1);

  
  return 0;
}
