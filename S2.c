#include <stdio.h>
#include<math.h>

//在函数上方输入/**回车即可生成该函数体的说明
/**
 * @brief 交换输入的变量a与变量b的值
 *
 * @param a
 * @param b
 * @return *** void
 * 注：调用语句   S2_P35_Q4_1_exchangeAB(&a,&b)
 */
void S2_P35_Q4_1_exchangeAB(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief 获得一个数组中的最大值
 * 
 * notice:数组名作为函数参数传递时,传递的仅仅是数组的首地址，或者说传递的是地址的指针变量，此时使用sizeof(数组名),不能得到数组的大小，仅能得到该地址存储数据的大小
 * @param array 数组首地址
 * @param n     数组长度
 * @return int  返回数组中的最大值
 * 注：调用语句  max=S2_P35_Q4_2_maxvalueinarray(array1,sizeof(array1)/sizeof(array1[0]));
 */
int S2_P35_Q4_2_maxvalueinarray(int array[], int n)
{

    int max = array[0];
    for (int i = 1; i < n; i++)
    {
        if (max<array[i])
        {
            max=array[i];
        }
        
    }
    return max;
}
/**
 * @brief 数组冒泡排序,从小到大排序
 * 
 * @param array 数组
 * @param n  数组长度
 * 函数调用示例： int *p = S2_P35_Q4_3_arraysort(array1, sizeof(array1) / sizeof(array1[0]));
 *  遍历排序后的数组：
 *  for (int i = 0; i < sizeof(array1) / sizeof(array1[0]); i++)
    {
        printf("%d\r\n", *(p + i));
    }
 */
int *S2_P35_Q4_3_arraysort(int array[],int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(array[j]>array[i])
            {
                array[i]=array[j];
            }
        }
    }
    return array;
}
/**
 * @brief 求m,n之间的最大公约数
 * 
 * @param m 
 * @param n 
 * @return int 返回m,n的最大公约数
 * 引用：printf("%d\r\n",S2_P35_Q4_7_mngreatestcommondivisor(24,36));
 */
int S2_P35_Q4_7_mngreatestcommondivisor(int m,int n)
{
    int r=0;//作为用于判断的余数
    if (n>m)
    {
        S2_P35_Q4_1_exchangeAB(&m,&n);
    }
    r=m%n;
    while(r!=0)
    {
        m=n;
        n=r;
        r=m%n;
    }
    return n;
    
}