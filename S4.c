#include"S4.h"
#include<stdio.h>
#include<math.h>


/**
 * @brief 对if语句的深入理解，该实例为分段函数sign函数，x<0,y=-1;x=0,y=0;x>0,y=1;
 * 注意：1、if else语句相当于将当前区域一分为2,要有这个概念，且else总是与最靠近它的未结对的if结对，为防止if else语句结构混乱，采用锯齿形状布局，一般把内嵌的if语句放到外层的else语句中，类似模块二
 * 浮点数运算时，本来应该等于0的数，由于精度问题，可能出现不等于0的情况，于是判定当该值小于一个很小的数时(1e-6)时，认为该值为0;
 * @param x 
 */
void S4_ifcomprehend(float x)
{
    {
        int y;
        if(x<0)
            y=-1;
        else  
            if(x<1e-6)y=0;
            else y=1;
        printf("%f的符号函数值为%d\r\n",x,y);
    }
    {
        int y;
        if(x>=1e-6)
            if(x>1e-6) y=1;
            else y=0;
        else y=-1;
        printf("%f的符号函数值为%d\r\n",x,y);
    }

}
/**
 * @brief 用三种选择语句判断闰年
 * 
 * @param year 
 */
void S4_P102_Q4_8_leapyearadjust(int year)
{
    /**
     * @brief if else嵌套语句判断闰年
     * 
     */
    {
        int flag=0;
        if(year%4==0)
        {
            if(year%100!=0) flag=1;
            else if(year%400==0) flag=1;
        }
        if(flag==1) printf("%d年是闰年\r\n",year);
    }
    /**
     * @brief 逻辑表达式判断闰年
     * 
     */
    {
        if((year%4==0&&year%100!=0)||year%400==0) printf("%d年是闰年\r\n",year);
    }
}
/**
 * @brief 输入10000以内的正整数，输出1：该数是几位数，2：该数的每一位数，3：逆序输出该数，自己解决，比书本上的答案更精简，逻辑相对复杂点
 * 
 * @param value 
 */
void S4_P109_Q9_AnserforMyself(int value)
{
    if(value>=10000||value<0)
    {
        printf("请输出10000以内的正整数");
    }
    int temp[4];
    int tempvalue=value;
    int NumericalSize;
    //将输入的value按位存放在temp[4]数组中
    temp[0]=value/1000;
    value=value-temp[0]*1000;
    temp[1]=value/100;
    value=value-temp[1]*100;
    temp[2]=value/10;
    value=value-temp[2]*10;
    temp[3]=value;
    //判断value是几位数，由遇到的第一个不为0的数在第几位，可以value是几位数。
    for(int i=0;i<4;i++)
    {
        if(temp[i]!=0) 
        {
            NumericalSize=4-i;
            printf("%d是%d位数\r\n",tempvalue,NumericalSize);
            break;
        }
    }
    //根据value是几位数，逆序输出即可
    printf("%d的逆序输出为:",tempvalue);
    for (int i = 0; i < NumericalSize; i++)
    {
        printf("%d",temp[3-i]);
    }
    printf("\n");
}
/**
 * @brief 输入10000以内的正整数，输出1：该数是几位数，2：该数的每一位数，3：逆序输出该数，书本答案，有借鉴意义
 * 
 * @param value 
 */

void S4_P109_Q9_AnserforBook(int num)
{
    int indiv,ten,hundred,thousand,place;
    if(num>999)
        place=4;
    else if(num>99)
        place=3;
    else if(num>9)
        place=2;
    else place=1;
    printf("%d的位数为%d位数",num,place);
    thousand=num/1000;
    hundred=(int)(num-thousand*1000)/100;
    ten=(int)(num-thousand*1000-hundred*100)/10;
    indiv=(int)(num-thousand*1000-hundred*100-ten*10);
    switch(place)
    {
        case 4:printf("各个位的输出为:%d,%d,%d,%d\n",thousand,hundred,ten,indiv);
            printf("逆序输出为：");
            printf("%d%d%d%d\n",indiv,ten,hundred,thousand);
            break;
        case 3:printf("各个位的输出为:%d,%d,%d\n",hundred,ten,indiv);
            printf("逆序输出为：");
            printf("%d%d%d\n",indiv,ten,hundred);
            break;
        case 2:printf("各个位的输出为:%d,%d\n",ten,indiv);
            printf("逆序输出为：");
            printf("%d%d\n",indiv,ten);
            break;
        case 1:printf("各个位的输出为:%d\n",indiv);
            printf("逆序输出为：");
            printf("%d\n",indiv);
            break;
    }
}

/**
 * @brief 求点(x1,y1)到(x2,y2)的距离，S4_P109_Q11中用到的求距离函数,vscode中sqrt(value)函数有问题，暂时不用
 * 
 * @param x1 
 * @param y1 
 * @param x2 
 * @param y2 
 */
float AskDistance(float x1,float y1,float x2,float y2)
{
    float distance=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
    return distance;
}

int S4_P109_Q11(float x,float y)
{
    float dis1,dis2,dis3,dis4;
    dis1=AskDistance(x,y,2,2);
    dis2=AskDistance(x,y,-2,2);
    dis3=AskDistance(x,y,-2,-2);
    dis4=AskDistance(x,y,2,-2);
    if(dis1<1||dis2<1||dis3<1||dis4<1) return 10;
    return 0;

}