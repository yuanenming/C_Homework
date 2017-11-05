#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 100
#define DEFAULT 5
#define MAXLEN 100

int getline_(char *line, int max);
void error(char *s);

int main(int argc, char * argv[]){
  char* to_print[MAXLINE];
  char line[MAXLEN];
  int i, nlines, n, len;
  if ( argc == 1)
    n = DEFAULT;
  else if (argc == 2 && (*++argv)[0] == '-')
    n = atoi(argv[0] + 1);
  else
    error("usage: tail [-n]");
  if (n < 1){
    error("usage: tail [-n] \n n must be positive.");
    return -1;}
  else if(n > MAXLINE){
    error("n is too large to handle.");
    return -1;}
    nlines=0;
  while((len = getline_(line,MAXLINE)) > 0)
      strcpy(to_print[nlines],line);
   // error("Bad usage: input lines are fewer than lines wanted to handle ");
  for(i = nlines - n; n-- > 0; i++)
    printf("%s",to_print[i]);
  return 0;
}

void error(char *s){
  printf("%s\n",s);
  exit(1);
}

/*
 int readlines( char *to_print[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];
  nlines = 0;
  while((len = getline_(line, MAXLEN))>0)
    {
    
      strcpy(to_print[nlines++], line);
      // to_print[nlines++] = p;
    }
  return nlines;
} */

int getline_(char * s, int max){
  int c, i;
    
  for (i=0; i<max-1 && (c=getchar())!=EOF && c !='\n';++i)
    s[i] = c;
  if (c == '\n')
    {
      s[i] = c;
      ++i;
    }
  s[i] = '\0';
  return i;
}
