
#include<stdio.h>
#include<ctype.h>
//支持科学计数法的打印数字函数
double atof_(char s[])
{
    double val,power;
    int i, sign, exp;
    for(i = 0; isspace(s[i]); i++)   //跳过空字符
        ;
    sign = (s[i] == '-') ? -1:1;     //判断符号位
    if(s[i] == '+'||s[i] == '-')
        i++;
    for(val=0.0; isdigit(s[i]);i++)  //处理整数部分
        val = 10.0 * val + (s[i] -'0');
    if(s[i] == '.')                     //是否有小数点
        i++;
    for(power = 1.0; isdigit(s[i]); i++)  //处理小数位
    {
        val = 10.0 *val + (s[i] - '0');
        power *= 10;
    }
    val = sign * val/power;             //计算val
    if(s[i] == 'e' || s[i] == 'E')     //判断是否存在科学计数法
    {
        sign = (s[++i] == '-')? -1:1;   //科学计数法内的符号位判断
        if(s[i] == '-' || s[i] == '+')
            i++;
        for (exp =0; isdigit(s[i]);i++) //处理指数
            exp = 10 * exp + (s[i]-'0');
        if(sign ==1)                      //利用循环进行指数运算
            while(exp-- > 0)
                val *= 10;
        else
            while(exp-- > 0)
                val /= 10;
    }
    return val;
}
int main()
{
    char s1[] = "9.8E-4";
    char s2[] = "-123.456";
    char s3[] = "-123.456e3";
    char s4[] = "    -123.456e3";
    printf("%g\n%g\n%g\n%g\n",atof_(s1),atof_(s2),atof_(s3),atof_(s4));
    return 0;
}


