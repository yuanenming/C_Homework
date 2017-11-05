#include<stdio.h>

void escape(char s[], char t[])   /*用数组写一个escape函数*/
{
    int i,j;
    for(i = j = 0; t[j] != '\0'; j++)
        
        switch(t[j]){
            case '\n':          /*转换换行符*/
                s[i++]='\\';
                s[i++]='n';
                break;
            case '\t':          /*转换制表符*/
                s[i++]='\\';
                s[i++]='t';
                break;
            default:            /*处理其他字符*/
                s[i++]=t[j];
                break;
        }
    s[i]='\0';
}

void unescape(char *s, char *t)    /*用指针写一个unescape函数*/
{
    while( *t != '\0')                 /*读入一个字符*/
        switch(*t){
            case '\\':                 /*处理'//'*/
                switch(*++t){
                    case 'n':*s++ = '\n';t++;break;    /*处理换行符*/
                    case 't':*s++ = '\t';t++;break;    /*处理制表符*/
                    default:*s++ = '\\';*s++ = *t++;break; /*非转义字符*/
                }
                break;
            default:*s++ = *t++;break;            /*处理其他字符*/
        }
    *s = '\0';
}
int main()
{
    char str1[]="Do  you like\tprograming?\nYes,of course.";
    char str2[100];
    char str3[100];
    escape(str2, str1);
    unescape(str3,str2);
    printf("%s\n\n%s\n\n%s\n",str1,str2,str3);
    return 0;
}
