#include<stdalign.h>
#define STACKSIZE 10
        // implantasyon
typedef struct
{
    struct node *top;
    int cnt;
}stack;
        // initialize
void initialize(stack *stk)
{
    stk->top = NULL;
    stk->cnt = 0;
}
        // push
void push(stack *stk, int x)
{
    if(stk->cnt == STACKSIZE)
        printf("stack dolu");
        else
        {
            stack node *temp = (node)malloc(sizeof(node));
            temp->data = x;
            temp->next = top;
            stk->top = temp;
            stk->cnt ++;
        }
}
        // pop
int pop(stack *stk)
{
    if(stk->cnt == 0)
    {
        printf("stack bos");
        return 0;
    }
    else
    {
        int x = stk->top->data;
        struct node *temp = stk->top;
        stk->top = stk->top->next;
        free(temp);
        stk->cnt --;
        return x;
    }
}
