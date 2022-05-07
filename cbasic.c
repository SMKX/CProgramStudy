#include"cbasic.h"
#include<stdio.h>


//计算1-1/2+1/3-1/4+...-1/100
void jclist()
{
    float sum=1.0,term;
    int valuesign=1;
    for(int i=2;i<100;i++)
    {
        valuesign=-valuesign;
        term=valuesign*(float)1/i;
        printf("%f\n",term);
        sum=sum+term;
        printf("%f\n",sum);
    }
    

}
//if and swith实现语句，实例，输入成绩判断
void myifandswitch(int grade,int value)
{
    //if语句
    if(grade<=100)
        if(grade>=90) 
            printf("成绩为A\n");
        else if(grade>=80)
            printf("成绩为B\n");
            else if(grade>=70)
                printf("成绩为C\n");
                else if(grade>=60)
                    printf("成绩为D\n");
                    else if(grade>=0)
                        printf("成绩不及格\n");
                        else 
                            printf("成绩错误，为负数\n");
    else
        printf("成绩错误,超过100\n");


    //else语句
    switch(value)
        {
        case 'A':printf("90-100\n");break;
        case 'B':printf("80-90\n");break;
        case 'C':printf("70-80\n");break;
        case 'D':printf("60-70\n");break;
        default:printf("不及格\n");break;
        }    



}


//循环
void myforandwhile()
{
   int i=1,sum=0;
    while(i<=100)
        {
            sum=sum+i;
            i++;
            
        }
    printf("sum的值为:%d",sum);

}
//求2/1+3/2+5/3+8/5+13/8+.....
int test(int n)
{
    float sum=0;
    //生成两个数组
    
    float a[n];
    a[0]=1.0;a[1]=2.0;
    float b[n];
    b[0]=2.0;b[1]=3.0;
    for(int i=2;i<n;i++)
    {
        a[i]=a[i-1]+a[i-2];
        b[i]=b[i-1]+b[i-2];
    }
    /***
    for(int i=0;i<n;i++)
    {
        printf("a数组第%d个值为:%f\r\n",i,a[i]);
        printf("b数组第%d个值为:%f\r\n",i,b[i]);
    }
    ***/
    for(int i=0;i<n;i++)
        {
            sum+=b[i]/a[i];
        }
    printf("%f",sum);
    sum=(int)sum;
    return sum;


}
