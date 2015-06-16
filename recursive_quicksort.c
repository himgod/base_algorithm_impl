#include<stdio.h>
#include<stdlib.h>


int quick(int* list,int begin,int end)
{
    int key = list[begin];
    int low = begin;
    int high = end;

    while(low < high)
    {
        while(low < high && list[high] > key)
        {
            high--;
        }
        if(low < high)
        {
            list[low] = list[high];
            low++;
        }

        while(low < high && list[low] < key)
        {
            low++;
        }

        if(low < high)
        {
            list[high] = list[low];
            high--;
        }

    }
    list[low] = key;
    return low;
}
void quick_sort(int* list,int begin,int end)
{
    int i = 0;
    if( begin  < end)
    {
        i = quick(list,begin,end);
        quick_sort(list,begin,i-1);
        quick_sort(list,i+1,end);
    }
}
int main()
{
    int i = 0;    
    int array[] = {3,6,9,1,4,2,6,8}; 
    quick_sort(array,0,7);
    printf("after quick sort:\n");
    for(i = 0; i < 8;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}

