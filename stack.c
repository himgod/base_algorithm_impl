#include<stdio.h>
#include<stdlib.h>

typedef int data_type;

typedef struct stack_node
{
    data_type data; 
    struct stack_node* next;
}s_node;

typedef struct stack{
    s_node* top;
    s_node* bottom;
}stack;


stack* push(stack* s,data_type value)
{
    s_node* tmp = (s_node*)malloc(sizeof(s_node));
    tmp->data = value;
    tmp->next = NULL;

    if(s->top == NULL)
    {
        s->top = s->bottom = tmp;
    }
    else
    {
            
        s->top->next = tmp;
        s->top = tmp;
    }

    return s;
}

stack* pop(stack* s)
{
   if( s->bottom == NULL )
   {
        fprintf(stderr,"empty stack\n");
        return NULL;
   }

   s_node* tmp;
   int x;

   tmp = s->bottom;
   if( tmp == s->top )
   {

        x = tmp->data;
        s->top = NULL;
        s->bottom = NULL;
   }
   else
   {
        while( tmp->next != s->top )
        {
                
            tmp = tmp->next;
        }
        x = tmp->data;
        s->top = tmp;
        s->top->next = NULL;
   }

  printf("%d ",x);
  return  s;
}

int top(stack* s)
{
    if( s->top == NULL )
    {
        fprintf(stderr,"empty stack\n");
        return -1;
    }

    return s->top->data;
}

int main()
{
    data_type test_data[] = {1,2,3,4,5};
    int i = 0;

    stack*s = (stack*)malloc(sizeof(stack));
    for( i = 0; i < 5; i++ )
    {
        s = push(s,test_data[i]);
    }
  
    printf("stack top element is:%d\n",top(s));    
    pop(s);
    printf("after pop ,stack top element is:%d\n",top(s));    
    return 0;
}
