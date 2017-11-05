#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 100       //定义输入的最大行数
#define DEFAULT 5         //定义默认的输出行数
#define MAXLEN 100        //定义每行的最大长度

int getline_(char *line, int max);       //getline函数读取输入行，返回字符串长度
void error(char *s);                     //报错函数
int readlines(char *to_print[],int nlines);  //readline函数把每行存储到字符指针数组中，返回行数
void writelines(char *[],int nlines,int n );          //打印倒数n行

int main(int argc, char * argv[]){
  char* to_print[MAXLINE];
  int i, nlines, n;
  if ( argc == 1)                             //无命令行参数
    n = DEFAULT;
  else if (argc == 2 && (*++argv)[0] == '-')  //处理命令行参数
    n = atoi(argv[0] + 1);
  else                                         //其他情况
  {
      error("usage: tail [-n]");
      return -1;}
  if (n < 1){                       //命令行参数数值超出范围
    error("usage: tail [-n] \n n must be positive.");
    return -1;}
  else if(n > MAXLINE){
    error("n is too large to handle.");
    return -1;}
    printf("Please input a few lines and ended with a line starting with a ;\n");
    
  if((nlines = readlines(to_print,MAXLINE)) <n)     //输入行数太多
    error("Bad usage: input lines are fewer than lines wanted to handle ");
  if(nlines >= 0)
      writelines(to_print,nlines,n);
  return 0;
}

void error(char *s){
  printf("%s\n",s);
  exit(1);
}

int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];
    
    nlines = 0;
    while ((len = getline_(line, MAXLEN)) > 0)
        if ( nlines >= maxlines || (p = malloc (len)) == NULL )
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy (p, line);
            lineptr[nlines++] = p;
        }
    return nlines; 
}


int getline_ (char *s, int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n' && c != ';')
        s[i++] = c;
    if (c == '\n' )
        s[i++] = c;
    else if (c == ';') return i;
    
    s[i] = '\0';
    return i; 
}

void writelines(char *lineptr[], int nlines,int n) {
    int i;
    for (i = nlines-n; i < nlines; i ++)
        printf("%s\n", lineptr[i]);
}


