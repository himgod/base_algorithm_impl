#include<stdio.h>
#include<stdlib.h>

int heap_size = 0;

//a[0] means array's length
static inline int parent(int i)
{
    return i/2;
}

static inline int left(int i)
{
    return 2*i;
}

static inline int right(int i)
{
    return 2*i+1;
}


void max_heapify(int a[],int i)
{
    int largest;
    int left_index = left(i);
    int right_index = right(i);
    if( heap_size >= left_index && a[left_index] > a[i] )
    {
        largest = left_index;
        
    }
    else
    {
        largest = i;
    }

    if( heap_size >= right_index && a[right_index] > a[largest])
    {
        largest = right_index;
    }

    if( largest != i )
    {
        //int temp = a[i];
        // a[i] = a[largest];
        // a[largest] = temp;
        swap(&a[i],&a[largest]);
        //max_heapify(a,largest);
        while(left(largest) <= heap_size || right(largest) <= heap_size)
        {
            int tmp_largest = 0;
            if(a[left(largest)] < a[largest] && a[right(largest)] < a[largest])
            {
                break;
            }
            else
            {
                if(a[largest] < a[left(largest)])
                {
                    tmp_largest = left(largest);
                }
                if(a[tmp_largest] < a[right(largest)])
                {
                    tmp_largest = right(largest);
                }

                if(tmp_largest != largest)
                {
                    //int tmp_val = a[largest];
                    // a[largest] = a[tmp_largest];
                    // a[tmp_largest] = tmp_val;
                    swap(&a[largest],&a[tmp_largest]);
                    largest = tmp_largest;
                }
            }

        }
    }
}


void build_max_heap(int a[])
{
    heap_size = a[0];

    int i;
    for(  i = a[0]/2; i > 0; i--)
    {
        max_heapify(a,i);
    }
}

void swap(int *a,int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heap_sort(int a[])
{
    build_max_heap(a);
    int i;
    for( i = a[0];i > 1; i--)
    {
        //int temp = a[i];
       // a[i] = a[1];
       // a[1] = temp;
        swap(&a[i],&a[1]);
        heap_size = heap_size-1;
        max_heapify(a,1);
    }
}


//priority queue's operation
//eg: heap_maximum,heap_extract_max,heap_increase_key and so on

int heap_maximum(int a[])
{
    return a[1];
}

//runtime O(lgn)
int heap_extract_max(int a[])
{
    if(heap_size < 0)
    {
        printf("empty priority queue");
        return -1;
    }
    int max = a[1];
    a[1] = a[heap_size];

    heap_size = heap_size - 1;
    max_heapify(a,1);
    return max;
}

//key element a[i] increase to somewhat value
int heap_increase_key(int a[],int i,int key)
{
    if( a[i] < key )
    {
        printf("new key is smaller than current key");
        return -1;
    }

    a[i] =  key;

    while( i > 1 && a[parent(i)] < a[i])
    {
        swap(&a[i,a[parent(i)]]);
        i = parent(i);
    }
}

//insert a new key into the heap
int max_heap_insert(int a[],int key)
{
    heap_size = heap_size + 1;
    a[heap_size] = -99999;
    heap_increase_key(a,heap_size,key);
    return 0;
}
int main()
{
    int i = 0;
    int a[] = {9,1,2,8,6,10,4,3,5,7};
    printf("before build heap:\n");
    for( i = 1; i <= a[0];i++ )
    {
        printf("%d ",a[i]);
    }
    printf("\n");
   // build_max_heap(a);
    //printf("after build heap:\n");
    //for( i = 1; i <= a[0];i++ )
   // {
   //     printf("%d ",a[i]);
   // }
    printf("\n");
    heap_sort(a);
    printf("after heap_sort:\n");
    for(i = 1; i <= a[0]; i++ )
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
