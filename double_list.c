#include<stdio.h>
#include<stdlib.h>


typedef struct student{
    int data;
    struct student* next;
    struct student* pre;
}node;

node* create_double_list(node* head)
{
    node* p,*tmp = NULL;
    p = head = (node*)malloc(sizeof(node));

    if( NULL == head || NULL == p )
    {   
        printf("memory allocated failed\n");
        return NULL; 
    }
    int x;
    scanf("%d\n",&x);
    while( x != 0 )
    {
        tmp = (node*)malloc(sizeof(node));
        tmp->data = x;
        p->next = tmp;
        tmp->pre = p;
        p = tmp;
        scanf("%d\n",&x);
    }
    head = head->next; 
    head->pre = NULL;
    p->next = NULL;
    return head;

}

node* del_double_list(node* head,int data)
{
    if( NULL == head )
    {
        return NULL;
    }

    node* p0;
    node* p = head;
    while( p->next != NULL && p->data != data )
    {
        p0 = p;
        p = p->next;
    }

    if( data == p->data )
    {
        if( p == head )
        {
            head = p->next;
            head->pre = NULL;
            free(p);
        }
        else if( p->next == NULL )
        {
            p0->next = NULL;
            free(p);
        }
        else
        {
            p0->next = p->next;
            p0 = p->next->pre;
            free(p);
        }
    }
    else
    {
        printf("%d element not in this list.\n",data);
    }
    return head;
}


node* insert_double_list(node* head,int data)
{
    if( NULL == head )
    {
        return NULL;
    }

    node* tmp = (node*)malloc(sizeof(node));
    if( tmp == NULL )
    {
        printf("memory allocated failed\n");
        return NULL;
    }
    tmp->data = data;
    node* p = head;
    node* p0 = NULL;
    while( p->next != NULL && p->data < data )
    {
        p0 = p;
        p = p->next;
    }

    if( p->data > data )
    {
       if( p == head )
       {
            head = tmp;
            head->next = p;
            p->pre = head;
            head->pre =NULL;
       }
       else
       {
            p0->next = tmp;
            p0 = tmp->pre;
            tmp->next = p;
            p->pre = tmp;
       }
    }
    else
    {
        p->next = tmp;
        tmp->pre = p;
        tmp->next = NULL;
    }
    return head;
}
void print_list(node* head)
{
   if( NULL != head )
   {
        node* tmp = head;
        while( tmp != NULL )
        {
            printf("%2d",tmp->data);
            tmp = tmp->next;
        }
        printf("\n");
   }
}


int main()
{
    node* head = NULL;
    head = create_double_list(head);
    if( NULL != head )
    {
        print_list(head);
        printf("The first data's element is: %d\n",head->data);
        printf("The second data's element is: %d\n",head->next->data);
        printf("The second data's pre's node's element is: %d\n",head->next->pre->data);
        head = del_double_list(head,3);
        printf("after del this element 3\n");
        print_list(head);
        head = insert_double_list(head,3);
        printf("after insert this element 3\n");
        print_list(head);
    }
    return 0;

}
