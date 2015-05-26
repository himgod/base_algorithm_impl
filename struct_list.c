#include<stdio.h>
#include<stdlib.h>

typedef struct student{
    int data;
    struct student *next;
}node;

node* create()
{
    int x = 0;
    node*p,*p1,*head;
    head = (node*)malloc(sizeof(node));
    p = head;
    if( p == NULL || head == NULL )
    {
        printf("memory malloced error\n");
        return;
    }
    scanf("%d\n",&x);
    while( x != 0 )
    {
        p1 = (node*)malloc(sizeof(node));
        p1->data = x;
        p->next = p1;
        p = p1;
        scanf("%d\n",&x);
    }
    head = head->next;
    p->next = NULL;
    return head;
    //free(p);
}

int list_len(node* head)
{
    int len = 0;
    node* tmp = head;
    while(tmp != NULL)
    {
        tmp = tmp->next;
        len++;
    }    
    return len;

}

void print_list(node* head)
{
    node* tmp = head;
    while( tmp != NULL )
    {
        printf("%d\n",tmp->data);
        tmp = tmp->next;
    }
}

node* insert_list(node* head,int num)
{
    node* tmp = head;
    node* p = (node*)malloc(sizeof(node));
    p->data = num;
    node* p1;
    while( tmp != NULL && tmp->data < num )
    {
        p1 = tmp;
        tmp = tmp->next;
    }
    //printf("%d\n",tmp->data);
    if( tmp != NULL && tmp->data >= num )
    {
        if( tmp == head )
        {
            p->next = tmp;
            head = p;
        }
        else
        {
            p1->next = p;
            p->next = tmp;

        }

    }
    else
    {
        p1->next = p;
        p1->next->next = NULL;
        //tmp->next->next = NULL;
    }
    return head;
}

node* del_list(node* head,int num)
{
    node* tmp = head;
    node* p;
    while(tmp->data != num && tmp->next != NULL)
    {
        p = tmp;
        tmp = tmp->next;
    }

    if( tmp->data == num )
    {
        if(head == tmp)
        {
            head = tmp->next;
            free(tmp);
        }
        else if( tmp->next == NULL )
        {
            p->next = NULL;
            free(tmp);
        }
        else
        {
            p->next = tmp->next;
            free(tmp);
        }
    }
    else
    {
        printf("没有对应的元素\n");
    }

    return head;
}

node* list_sort(node* head)
{
    if( head == NULL || head->next == NULL )
    {
        return head;
    }
    node* tmp = head;

    int len = list_len(head);
    int i = 1,j = 0;
    for( i = 1;i < len;i++ )
    {
        tmp = head;
        for( j = 0; j < len-i;j++ )
        {
            if( tmp->data > tmp->next->data )
            {
                int tmp_data = tmp->data;
                tmp->data = tmp->next->data;
                tmp->next->data = tmp_data;
            }
            tmp = tmp->next;
        }
    }
    return head;
}

node* list_reverse(node* head)
{
    if( head == NULL || head->next == NULL )
    {
        return head;
    }
    node* p1,*p2,*p3;
    p1 = head;

    p2 = head->next;
    while(p2)
    {
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }

    head->next = NULL;
    head = p1;
    return head;
}

node* list_mid_search(node* head,node* mid)
{

    if( head->next->next == NULL || head->next == NULL || head == NULL )
    {
        return head;
    }
    node* tmp = head;
            
    while( head->next != NULL )
    {
        head = head->next->next;
        tmp = tmp->next;
        mid = tmp;
    }
    return mid;
}
int main()
{
    node* head = NULL;
    int retNum;
    node* mid =  NULL;
    head = create();
   // printf("%d\n",head->data);
    if(head != NULL )
    {
        printf("helloworld\n");
        printf("length is:%d\n",list_len(head));
        print_list(head);
        printf("list_sort.................\n");
        head = list_sort(head);
        print_list(head);
        printf("insert_list................\n");
        head = insert_list(head,3);
        printf("length is:%d\n",list_len(head));
        print_list(head);
        printf("del_list....................\n");
        head = del_list(head,3);
        printf("length is:%d\n",list_len(head));
        print_list(head);
        printf("list_reverse................\n");
        head = list_reverse(head);
        print_list(head);
        printf("list_mid_search()...............\n");
        mid = list_mid_search(head,mid);
        if( mid != NULL )
        {
            printf("mid data is:%d\n",mid->data);
        }
    }
    return 0;
}
