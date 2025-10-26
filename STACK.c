#include <stdio.h>
#include <ctype.h>

#define STACKSIZE 10
        // implantasyon
typedef struct
{
    int data[STACKSIZE];
    int top;
}stack;
        // reset
void reset(stack *stk)
{
    stk->top = -1;
}
        // push
void push(stack *stk, int x)
{
if(stk->top == STACKSIZE)
    {
    printf("stack dolu/n");
    }
else
    {
    stk->top++;
    stk->data[stk->top] = x;
    }
}
        // pop
int pop(stack *stk)
{
    if(stk->top == -1)
    {
        printf("stack bos/n");
        return 0;
    }
    else
        {
            int x = stk->data[stk->top];
            stk->top --;
            return x;
        }
}
int main()
{
    stack s;
    reset(&s);
    char exp[20];
    char *e;
    printf("Bir ifade giriniz: ");
    scanf("%s",exp);

    e = exp;
    while(*e != '\0')
    {
        if(isdigit (*e))
        {
            int num = *e - 48;// atoi(*e);
            push(&s,num);
        }
        else
            {
                int n1 = pop(&s);
                int n2 = pop(&s);
                switch(*e)
                {
                    case '+' : push(&s,n2+n1);
                    break;
                    case '-' : push(&s,n2-n1);
                    break;
                    case '*' : push(&s,n2*n1);
                    break;
                    case '/' : push(&s,n2/n1);
                    break;
                }
            }
            e++;
    }
    printf("%s = %d",exp,pop(&s));
}
