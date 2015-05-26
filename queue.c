#include<stdio.h>
#include<stdlib.h>


typedef struct student{
    int data;
    struct student* next;
}node;

typedef struct queue{
    node* first,*rear;
}queue;

queue* insert_queue(queue* HQ,int x)
{
    node* s = NULL;
    s = (node*)malloc(sizeof(node));
    s->data = x;
    s->next = NULL;

    if( HQ->rear == NULL )
    {
        HQ->first = s ;
        HQ->rear = s;
    }
    else
    {
        HQ->rear->next = s ;
        HQ->rear = s;
    }
    return HQ;
}

queue* del_queue(queue* q)
{
    if( NULL == q || NULL == q->first )
    {
        return q;
    }
    
    int x = q->first->data;
    node* tmp = q->first;
    if( q->first == q->rear )
    {
        q->first = NULL;
        q->rear = NULL;
    }
    else
    {
        q->first = q->first->next;
        free(tmp);
    }
    printf("delete element %d\n",x);
    return q;
}
void print_queue(queue* q)
{
    if( q == NULL || q->rear == NULL )
    {
        return;
    }
    else
    {
        node* head = q->first;
        while( head != NULL )
        {
            printf("%d ",head->data);
            head = head->next;
        }
        printf("\n");
    }
}


int main()
{
    queue *q = (queue*)malloc(sizeof(queue)); 
    q = insert_queue(q,1);
    q = insert_queue(q,2);
    q = insert_queue(q,3);
    q = insert_queue(q,4);
    q= del_queue(q);
    if( q->rear != NULL )
    {   
        printf("q->rear not NULL\n");
        print_queue(q);
    }
    return 0;
}
