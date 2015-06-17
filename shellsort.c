#include<stdio.h>
#include<stdlib.h>

/*
 *先取一个小于n的整数作为d1作为第一个增量，把文件的全部记录分成d1个分组．
 *所有距离为d1的倍数的记录放在同一个组中．先在各组内进行直接插入排序，然后
 *取第二个增量d2<d1重复上述的分组和排序，直至所取的增量dt=1．

 *该方法实质上为一种分组插入方法
 */
void shell_pass(int array[],int len,int increment)
{
    int i = 0;
    for( i = increment; i < len;i++)
    {
        if( array[i] < array[i-increment])
        {
            int temp = array[i];
            int j = i - increment;
            while( j >= 0 && temp < array[j])
            {
                array[j+increment] = array[j];
                j = j - increment;
            }
            array[j+increment] = temp;
        }
    }
}
void shell_sort(int array[],int len)
{
    int i = 0;
    int count = 0;// 
    int increment = len;
    while(increment > 1)
    {
        increment = increment/3 + 1;
        printf("increment is:%d\n",increment);
        shell_pass(array,len,increment);
        printf("after %dth sort:\n",++count);
        for(i=0;i<len;i++)
        {
             printf("%d ",array[i]);
        }
        printf("\n");
    }
}
int main()
{
    int i;
    int array[] = {49,38,65,97,76,13,27,49,55,4};
    int len = 10;
    shell_sort(array,len);
    printf("after shell sort:\n");
    for(i=0;i<len;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}
