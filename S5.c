#include <stdio.h>
#include <string.h>
#include "S5.h"

/**
 * @brief
 *
 * @param m
 * @param n
 * @param array 返回m,n的最大公约数与最小公倍数为array[0]和array[1]
 * 注意：若新建在函数内部的数组，在函数调用完后数组存储空间被销毁，在函数外部无法获取数组数值，解决办法，在函数外部定义数组，或将数组作为行参引入函数
 * 函数内部的静态存储的数组可以访问，此时数组不定义在堆栈区，指针不能指向堆栈区的储存空间，因其数据易变
 * @return int*
 * 引用示例
 *  int array[2];
    int *pointtest=S5_P137_Q3_MaxCommonDivsorAndMultiple(63,27,array);
    printf("最大公约数为:%d\n最小公倍数为:%d\n",*pointtest,*(pointtest+1));
 */
int *S5_P137_Q3_MaxCommonDivsorAndMultiple(int m, int n, int array[])
{
    // array[0]存小值，array[1]存大值
    array[0] = m;
    array[1] = n;
    if (m > n)
    {
        array[0] = n;
        array[1] = m;
    }
    //求最大公约数
    for (int i = array[0]; i > 0; i--)
    {
        if (m % i == 0 && n % i == 0)
        {
            array[0] = i;
            break;
        }
    }
    //求最大公倍数
    for (int i = array[1];; i++)
    {
        if (i % m == 0 && i % n == 0)
        {
            array[1] = i;
            break;
        }
    }

    return array;
}
/**
 * @brief 输入一行字符串，分析该字符串中英文字母个数，空格个数，数字个数和其他字符个数
 *
 */
void S5_P137_Q4_AnalyseStrForMyself()
{
    char c[30] = "I am a postgraduated123.";
    int letters = 0, space = 0, digit = 0, others = 0;
    for (int i = 0; i < (int)strlen(c); i++)
    {
        if ((c[i] >= 'A' && c[i] <= 'Z') || (c[i] >= 'a' && c[i] <= 'z'))
        {
            letters++;
            continue;
        }
        if (c[i] == ' ')
        {
            space++;
            continue;
        }
        if (c[i] >= '0' && c[i] <= '9')
        {
            digit++;
            continue;
        }
        others++;
    }
    printf("英文字母的个数为：%d,空格的个数为%d,数字的个数为%d,其他字符的个数为%d\n", letters, space, digit, others);
}

void S5_P137_Q4_AnalyseStrForBook()
{
    char c;
    int letters = 0, space = 0, digit = 0, others = 0;
    printf("请输入一个字符:\n");
    while ((c = getchar()) != '\n')
    {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            letters++;
        }else if (c == ' ')
        {
            space++;
        }else if (c >= '0' && c <= '9')
        {
            digit++;
        }else 
            others++;
    }
    printf("英文字母的个数为：%d,空格的个数为%d,数字的个数为%d,其他字符的个数为%d\n", letters, space, digit, others);
}

/**
 * @brief n!  用递归实现阶乘
 * 
 * @param n 
 * @return int 
 * 引用 printf("%d\n",S5_P137_Q6_factorial(5));
 */
int S5_P137_Q6_factorial(int n)
{
    if(n==1)
    {
        return 1;
    }
    return n*S5_P137_Q6_factorial(n-1);
}

/**
 * @brief n!+(n-1)!+....+2!+1!  用循环实现阶乘和
 * 
 * @param n 
 * @return int 
 * 引用：printf("%d\n",S5_P137_Q6_factorialSum1(4));
 */
int S5_P137_Q6_factorialSum1(int n)
{
    int sum=0,factorial=1;
    for (int i = 1; i <= n; i++)
    {
        factorial=factorial*i;
        sum+=factorial;
    }
    return sum;
}
