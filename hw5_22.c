#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFINES 5
#define LINES    100
#define MAXLEN   100

void error(char *);
int getline_(char *, int);

int main(int argc, char *argv[])
{
  char *p;
  char *buf;
  char *bufend;
  char line[MAXLEN];
  char *lineptr[LINES];
  int first, i, last, len, n, nlines;

  if(argc == 1)
    n = DEFINES;
  else if (argc == 2 && (*++argv)[0] == '-')
    n = atoi(argv[0]+1);
  else
    error("usage");
  if(n < 1|| n>LINES)
    n = LINES;
  for(i = 0;i<LINES;i++)
    lineptr[i] = NULL;
  if ((p = buf = malloc(LINES * MAXLEN)) == NULL)
    error("tail");
  bufend = buf + LINES * MAXLEN;
  last = 0;
  nlines = 0;
  while ((len = getline_(line,MAXLEN)) > 0)
    {
      if(p + len +1>= bufend)
	p = buf;
      lineptr[last] = p;
      strcpy(lineptr[last],line);
      if (++last >= LINES )
	last = 0;
      p += len +1;
      nlines++;
    }
  if(n > nlines)
    n = nlines;
  first = last -n;
  if (first < 0)
    first += LINES ;
  for(i = first;n-- >0;i = (i+1)%LINES)
    printf("%s",lineptr[i]);
  return 0;
}
void error(char *s)
{
  printf("%s\n",s);
  exit(1);
}

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

