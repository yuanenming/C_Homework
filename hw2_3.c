#include <stdio.h>
/* any(s1, s2), which returns the first location in the string s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.  */


int any(char s1[],char s2[])
{
    int i, j;
    for(i=0;s1[i] != '\0';i++)
        for(j=0;s2[j] != '\0';j++)
        {
            if(s1[i]==s2[j])
            return ++i;
        }
    return -1;
}

int main()
{
    int any(char s1[],char s2[]);
    char s1[]="This is the main sequence.", s2[]="subsequence";
 
    printf("%d      %d",any(s1, s2),any(s2,s1));
    return 0;
}
