#include <stdio.h>
#include <string.h>
#include "S6.h"
#include "S2.h"

/**
 * @brief 冒泡排序法，对参数数组进行排序，并返回
 * 冒泡排序，两两比较，将最大的值沉底到最下面，最小的值，则冒泡上行到最上面
 * @param array 
 * @param n 
 * @return int* 
 * 引用 int array1[]={60,50,55,70,78,99,85,61,89,91,45,72};
    int *pointer=S6_P165_Q2_sort1(array1,sizeof(array1)/sizeof(array1[0]));
    for (int i = 0; i < (int)(sizeof(array1)/sizeof(array1[0])); i++)
    {
        printf("%4d",*(pointer+i));
    }
    
 */
int *S6_P165_Q2_sort1(int array[],int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if(array[j]>array[j+1]) S2_P35_Q4_1_exchangeAB(&array[j],&array[j+1]);
        }
        
    }
    return array;

}
/**
 * @brief 选择排序法，选择将最小的放在数组第一个位置，做比较，有比第一个位置小的数，则进行交换。
 * 
 * @param array 
 * @param n 
 * @return int* 
 * 引用    
 *  int array1[]={60,50,55,70,78,99,85,61,89,91,45,72};
    int *pointer=S6_P165_Q2_sort2(array1,sizeof(array1)/sizeof(array1[0]));
    for (int i = 0; i < (int)(sizeof(array1)/sizeof(array1[0])); i++)
    {
        printf("%4d",*(pointer+i));
    }
 */
int *S6_P165_Q2_sort2(int array[],int n)
{   
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(array[i]>array[j])
            {
                S2_P35_Q4_1_exchangeAB(&array[i],&array[j]);
            }
        }
        
    }
    return array;

}
/**
 * @brief 输出n层杨辉三角形
 * 
 * @param n 
 */
void S6_P165_Q6_YHTriangle(int n)
{
    //数组定义，不允许使用不确定可变的量来限制数组大小，在该函数中，n变量作为行参是确定的，在该函数中是确定不变的
    int YHTriangle[n][n];
    //填充第一列和对角线的元素
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i==j) {
                YHTriangle[i][j]=1;
                continue;
            }
            if(j==0) {
                YHTriangle[i][j]=1;
                continue;
            }
            YHTriangle[i][j]=0;
        }
        
    }
    //填充除去第一列和对角线外的元素，满足公式YHTriangle[i][j]=YHTriangle[i-1][j]+YHTriangle[i-1][j-1];
    for (int i = 2; i < n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            YHTriangle[i][j]=YHTriangle[i-1][j]+YHTriangle[i-1][j-1];
        }
        
    }
    //输出杨辉三角形
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%3d",YHTriangle[i][j]);
        }
        printf("\n");
        
    }
}

/**
 * @brief 找出数组array1[m][n]中的鞍点，所谓鞍点，即这个点的值是在它所在行最大，在它的所在列最小
 * 
 * @param array1 
 * @param array2 
 * @param m 行数
 * @param n 列数
 * @return int* 
 * 几个注意的点
 * 1、数组作为实参和行参时，传递的是数组的首地址，所以实参和行参指向的是同一块存储区域，改变行参数组的数组元素值，相应的实参数组的数组元素值自然也改变，不需要返回数组地址
 * 2、一维数组实参和行参格式可为：调用function(array),函数定义void function(int array[]) 或void function(int *array)
 * 3、二位数组实参和行参格式可为：调用funciton(*array),函数定义void function(int array[][m]),二位数组定义，列数必须指定。或void function(int *array)
 * 
 * 引用
 * int array1[4][5]={{1,40,3,4,5},{11,30,4,5,1},{15,50,4,9,3},{20,100,4,8,9}};
 * S6_P165_Q8_SaddlePoint(*array1,(int)(sizeof(array1)/sizeof(array1[0])),(int)(sizeof(array1[0])/sizeof(array1[0][0])));
 * (int)(sizeof(array1)/sizeof(array1[0]))为二维数组行数
 * (int)(sizeof(array1[0])/sizeof(array1[0][0]))//为二维数组列数
 * 
 */

void S6_P165_Q8_SaddlePoint(int *array1,int m,int n)
{
    
    int max,maxj,flag;  
    for (int i = 0; i < m; i++)
    {
        max=*(array1+i*n+0);//把max初值设置为行第一个值
        maxj=0;
        //当前行比较
        for (int j = 0; j < n; j++)
        {
            if(*(array1+i*n+j)>max)
            {
                max=*(array1+i*n+j);
                maxj=j;
            }
        }
        flag=1;   //先假设是鞍点，flag=1为标志
        //maxj列比较
        for (int k = 0; k < m; k++)
        {
            if(max>*(array1+k*n+maxj))
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            printf("鞍点为array1[%d][%d]:%d\r\n",i,maxj,max);
        }
        
        
    }
    

    printf("%d,%d\r\n",m,n);
}
