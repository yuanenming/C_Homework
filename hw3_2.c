#include<stdio.h>
#define MAX 200
/*将速记符号转换完整,只转换数字与小写字母*/

void expand(char s1[], char s2[])                           /*定义返回值为空的函数expand*/
{
    char c;
    int i, j;
    
    i = j = 0;
    while ((c = s1[i++]) != '\0')                               /*遍历字符数s1中的字符*/
        if (s1[i] == '-' && ((s1[i-1] >= 'a' && s1[i+1]<='z'&& s1[i+1]>s1[i-1]) ||(s1[i-1] >= '0' && s1[i+1]<= '9'&&s1[i+1] >s1[i-1])))
        /*寻找s[i]中特定的'-'：不是在开头不是在结尾，而是在两个满足顺序的数字或者小写字母中间*/
        {
            i++;
            while (c < s1[i])                             /*扩写速记符号*/
                s2[j++] = c++;
        }
        else                                             /*拷贝其他符号*/
            s2[j++] = c;
    
}

int main()
{
    char str1[] = "-a\ta-g\t0-9\ta-b-c\t2-a\ta-f-g\t-0-9";
    char str2[MAX];
    expand(str1, str2);
    printf("string1:%s\nstring2:%s\n",str1,str2);
    return 0;
}
