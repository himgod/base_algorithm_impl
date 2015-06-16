#include<stdio.h>
#include<stdlib.h>

void bubble_sort(int* list ,int len)
{
    int i = 0,j = 0;
    int exchange = 0;

    for(i=1;i < len;i++)
    {
        exchange = 0;//unexchanged
        for( j = len-1;j >= i;j--)
        {
            if( list[j] < list[j-1])
            {
                int temp = list[j];
                list[j] = list[j-1];
                list[j-1] = temp;
                exchange = 1;
            }
        }
        if(exchange == 0)
        {
            return;
        }
    }
}
int main()
{
    int array[] = {2,4,9,4,6,8,1,3,5,7}; 
    int i = 0;
    bubble_sort(array,10);
    printf("after bubble sort:\n");
    for(i = 0; i < 10;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}
