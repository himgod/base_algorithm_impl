#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10

typedef struct{
    int list[MAXSIZE];
    int length;
}List;


int binary_search(List list,int key)
{
    int low = 0,high,mid;
    high = list.length-1;
    mid = (low+high)/2;

    while( high >= low )
    {
        if(list.list[mid] > key)
        {
            high = mid - 1;
            mid = (low+high)/2;
        }
        else if( list.list[mid] < key)
        {
            low = mid + 1;
            mid = (low+high)/2;
        }
        else
        {
            return mid+1;
        }

    }

    return 0;

}

int main()
{
    List s;
    int i,k,rst;
    int a[] = {1,3,6,12,15,19,25,32,38,87};
    for(i=0;i<MAXSIZE;i++)
    {
        s.list[i] = a[i];
    }
    s.length = MAXSIZE;

    printf("Input key number:");
    scanf("%d",&k);
    rst = binary_search(s,k);
    if(rst==0)
    {
        printf("Key:%d is not in the list!\n",k);
    }
    else
    {
        printf("The key is in the list,position is:%d\n",rst);
    }

    return 0;
}
