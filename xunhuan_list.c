#include<stdio.h>
#include<stdlib.h>


typedef struct xunhuan_list{
    int data;
    struct xunhuan_list* next;
}node;

node* create_xunhuan_list()
{
    node* head = (node*)malloc(sizeof(node));
    node* p = head;

    int x = 0;
    scanf("%d\n",&x);

    while( x != 0 )
    {
        node* tmp = (node*)malloc(sizeof(node));
        tmp->data = x;
        p->next = tmp;
        p = tmp;
        scanf("%d\n",&x);
    }
    head = head->next;
    p->next = head;
    return head;
}

void JOSEPHUS(int n,int k,int m)
{
    node* head,*tmp,*p,*p0;
    head = (node*)malloc(sizeof(node));
    p = head;

    int i = 0;
    for(i = 1;i < n+1;i++)
    {
        tmp = (node*)malloc(sizeof(node));
        tmp->data = i;
        p->next = tmp;
        p = tmp;
    }

    head = head->next;
    p->next = head;
    
    //find the kth element
    //head pointer means the current element
    p0 = head;
    printf("head's data %d\n",head->data);
    while( --k )
    {
        p0 = head;
        head = head->next;
    }

    printf("the start element's number is: %d\n",head->data);
    while( n-- )
    {
        int s = m;
        while( --s )
        {
            p0 = head;
            head = head->next;
        }
        p0->next = head->next;
        printf("%d->",head->data);
        free(head);
        head = p0->next;
    }
    printf("\n");
    
}
void print_list(node* head)
{
    if( NULL == head )
    {
        return;
    }
    while( head->next != NULL )
    {
        printf("%d ",head->data);
        head = head->next;
    }
}


int main()
{
    //node* head = create_xunhuan_list();
   // if( head != NULL )
    {
        //printf("%d",head->next->next->data);
    }
    JOSEPHUS(23,4,6);
    return 0;
}
