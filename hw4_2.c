#include<stdio.h>
#include<string.h>

char *reverse(char *s)
{
    char *reverse1(char *,int,int);
    return reverse1(s, 0, strlen(s));
}

char *reverse1(char *s,int start,int len)
{
    void swap(char*,char*);
    int j, tmp;
    
    j = len -(start + 1);
    if(start < j){
        swap(s+start,s+j);    ///dsf
        reverse1(s,++start, len);   ///sdfss
        
    }
    return s;
}

void swap(char *c, char *s)
{
    int tmp;
    tmp = *c;
    *c = *s;
    *s = tmp;
}

int main()
{
    char s[]="this is an example";
    printf("Input:%s\n",s);
    printf("Reverse:%s\n",reverse(s));
    return 0;
}
