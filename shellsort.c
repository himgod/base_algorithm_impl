#include<stdio.h>
#include<stdlib.h>

/*
 *��ȡһ��С��n��������Ϊd1��Ϊ��һ�����������ļ���ȫ����¼�ֳ�d1�����飮
 *���о���Ϊd1�ı����ļ�¼����ͬһ�����У����ڸ����ڽ���ֱ�Ӳ�������Ȼ��
 *ȡ�ڶ�������d2<d1�ظ������ķ��������ֱ����ȡ������dt=1��

 *�÷���ʵ����Ϊһ�ַ�����뷽��
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
