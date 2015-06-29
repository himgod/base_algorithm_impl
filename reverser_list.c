#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int value;
    struct node* next;
}node;

//创建链表
node* create_list(int n)
{
    node* head = (node*)malloc(sizeof(node));

    node* p = head;

    while(n)
    {
        node* temp = (node*)malloc(sizeof(node));
        printf("Input number:");
        scanf("%d",&temp->value);
        temp->next = NULL;
        p->next = temp;
        p = temp;
        n--;
    }
    head = head->next;
    //free(p);
    return head;
}


//翻转整个链表
//整个思想如下：
//三个指针构成，first,second,third为例.其中first表示第一个数字，second相对的第二数字,
//third辅助的第三个，用以保存后继链表的，作为下一个第二次指针的过度
//形如:1->2-->3-->4-->5,结果为
//5-->4-->3-->2-->1
node* reverse_list(node* head)
{
    node* first,*second,*third;
    if( head == NULL ||head->next == NULL )
    {
        return head;
    }

    first = head;
    second = first->next;

    while(second != NULL  )
    {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }

    //原先的首部变成为尾部,指向空指针
    head->next = NULL;
    //尾部变为新的头部指针
    head = first;

    return head;
}

//翻转链表前k个，并且分割为两个链表
//参数:head,二维指针，返回分割后列表的头部指针
//tail,二维指针，返回分割后前半部分的尾部指针
//返回值,被ｋ分割后后半部分链表的头部指针
//形如：1-->2-->3-->4-->5,k=3则结果:
//链表1:3-->2-->1
//链表2:4-->5
//其中head输出为3,tail输出为1;
//返回值为4
node* reverse_list_kth(node** head, node** tail,int k)
{
    int n = 1;
    node* first = NULL,*second = NULL,*third = NULL;
    node* next_head = NULL;
    //输入列表为空链表或者单个节点，或者ｋ为1,直接返回空指针即可．
    //对列表不做处理
    if( *head == NULL || (*head)->next == NULL || k == 1)
    {
        *tail = NULL;
        return NULL;
    }
    first = *head;
    second = first->next;
    while(second != NULL)
    {
       //翻转操作
       third = second->next;
       second->next = first;
       first = second;
       second = third;
       n++;
       //翻转达到ｋ个数，跳出循环
       if(n == k || second == NULL)
       {
            break;
       }
    }
    //记录后半部分链表的头部指针
    next_head = second;
    //记录前半部分链表的尾部指针
    *tail =  *head;
    // printf("tail is tail->value: %d\n",(*tail)->value);
    //分割链表
    (*head)->next = NULL;
    //重置前半部分链表的首部指针
    *head = first;
    return next_head;
}

//拼接链表
//参数head,表示输入链表
//参数ｋ为间隔k
//
node* reverse_list_interval_k(node* head,int k)
{
    //node* first,*second,*third;

    node* tmp_tail;
    node* tmp_tail_2;
    //第一次分割，记录保存最后的head指针
    //分割为head,tmp_tail首部和尾部指针构成的第一个链表
    //tmp_head是第二链表的头部指针
    node* tmp_head = reverse_list_kth(&head,&tmp_tail,k);
    //返回头部指针，也是合并后链表的头部指针
    node* new_head = head;
   
    //printf("%d\n",tmp_tail->value);
   // print_list(head);
   // print_list(tmp_head);
    while( tmp_tail != NULL )
    { 
        node* next_head;
        int len = list_len(tmp_head);
        printf("len=%d\n",len);
        //根据余下链表的长度判定是否继续翻转分割
        if( len >= k )
        {
            next_head = reverse_list_kth(&tmp_head,&tmp_tail_2,k);
        //print_list(tmp_head);
        // print_list(next_head);
            tmp_tail->next = tmp_head;
            tmp_tail = tmp_tail_2;
            tmp_head = next_head;
        }
        else
        {
            tmp_tail->next = tmp_head;    
            break;
        }
    }
    //print_list(head);
    return new_head;
}

//打印列表
void print_list(node* head)
{
    if( head == NULL )
    {
        return;
    }
    else
    {
        while(head != NULL )
        {
            printf("%d ",head->value);
            head = head->next;
        }
        printf("\n");
    }
}

//链表长度
int list_len(node* head)
{
    int len = 0;
    while(head != NULL)
    {
        head = head->next;    
        len++;
    }
    return len;
}
int main()
{
    node* list = create_list(6);
    print_list(list);
    printf("After kth reverse:\n");
    //list = reverse_list(list);
    //node* tmp_list = reverse_list_kth(&list,2);
   // print_list(tmp_list);
    printf("After k interval reverse\n");
    list = reverse_list_interval_k(list,3);
    print_list(list);
    return 0;
}
