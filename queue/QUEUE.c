#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>

#define QUEUESIZE   100
#define STACKSIZE    10
    // implantasuom
typedef struct{
    char data[STACKSIZE];
    int top;
    }stack;
    // reset
void stackReset(stack *stk){
    stk->top = -1;
    }
    // push
void push(stack *stk, char x){
    if(stk->top == STACKSIZE)
        printf("stack is full");
    else{
        stk->top ++;
        stk->data[stk->top] = x;
    }
    }
    // pop
int pop(stack *stk){
    if(stk->top == -1){
        printf("stack is empty");
        return 0;
    }else{
    char x = stk->data[stk->top];
    stk->top --;
    return x;
    }
    }

typedef struct{
    int front;
    int rear;
    int cnt;
    int data[QUEUESIZE];
    }queue;
    // isEmpty function
int isEmpty(queue *q){
    if(q->cnt == 0)
        return 1;
    else return 0;
    }
    // isFull function
int isFull(queue *q){
    if(q->cnt == QUEUESIZE)
        return 1;
    else
        return 0;
    }
    // reset function
void queueReset(queue *q){
    q->front = 0;
    q->rear = -1;
    q->cnt = 0;
    }
    // enqueue function
void enqueue(queue *q, int x){
    if(isFull(q))
        printf("the queue is full");
    else{
        q->cnt++;
        q->rear++;
        if(q->rear == QUEUESIZE)
            q->rear = 0;
        q->data[q->rear] = x;
    }
    }
    // dequeue function
int dequeue(queue *q){
    if(isEmpty(q)){
        printf("queue is empty");
        return 0;
    }else{
        int x = q->data[q->front];
        q->front++;
        q->cnt--;
        if(q->front == QUEUESIZE)
            q->front = 0;
        return x;
        }
    }

int main(){
    queue q;
    stack s;
    stackReset(&s);
    queueReset(&q);
    char str[100];
    gets(str);
    int i=0;
    while(i<strlen(str)){
        if(str[i] >= 'a' && str[i]<= 'z' || str[i]>= 'A' && str[i]<= 'Z'){
            push(&s, tolower(str[i]));
            enqueue(&q, tolower(str[i]));
        }i++;
    }while(! isEmpty(&q)){
        if(pop(&s)!= dequeue(&q)){
            printf(" not palindrome ");
            exit(0);
        }
        }
        printf("palindrome");
    }
