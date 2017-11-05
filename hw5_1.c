#include <stdio.h>
#include <string.h>

int strcmp_(char s[],char t[],int n)
{
    if(strlen(s)<strlen(t) || n <= 0)
    {
        printf("Bad using!\n");
        return -1;
    }
    int i, j=1;
    for ( i = 0; i < n-strlen(t); i++)
        if(t[0] == s[i++])
           for(; t[j] != '\0'&&t[j] == s[i];i++, j++);
    return (t[j] == '\0')?1:-1;
}

/*int main()
{
    char s[] = "abcdefghigklmn";
    char t[] = "efgh";
    printf("2nd string is %s in 1st string before n-th character.\n",(strcmp_(s,t,3)==1)?" ":"not");
    printf("2nd string is %s in 1st string before n-th character.\n",(strcmp_(s,t,5)==1)?" ":"not");
    printf("2nd string is %s in 1st string before n-th character.\n",(strcmp_(t,s,3)==1)?" ":"not");
    return 0;
}*/

int main(){
    char s1[]="example one",t1[]="one";
    char s2[]="example two",t2[]="exa";
    int n=5;
    printf("result of example one:%d\n",strcmp_(s1,t1,n));
    printf("result of example two:%d\n",strcmp_(s2,t2,n)); }







