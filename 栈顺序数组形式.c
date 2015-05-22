#include <stdio.h>
#include <stdlib.h>

#define ERROR -2
#define OVERFLOW 2
#define true 1
#define false 0
#define maesize 10

typedef int ElemType;

//顺序栈 数组的实现方式
typedef struct
{
    ElemType data[maesize];
    int top;
}SqStack;
//初始化一个空栈S
int InitStack(SqStack *S)
{
    S->top = -1;
}

//判断栈是否空，空返回true
int StackEmpty(SqStack S)
{
    if(S.top==-1){
        return true;
    }
    return false;
}

//进栈，若栈未满
int Push(SqStack *S,ElemType e)
{
    if(S->top==maesize-1){
        return false;
    }
    S->data[++S->top]=e;
    return true;
}

//出栈，若栈不为空
int Pop(SqStack *S,ElemType *e)
{
    if(S->top==-1){
        return false;
    }
    *e=S->data[S->top--];
    return true;
}

//读栈顶元素，并返回元素
int GetTop(SqStack S,ElemType *e)
{
    if(S.top==-1){
        return false;
    }
    *e=S.data[S.top];
    return true;
}



int main()
{
    ElemType e;
    SqStack S;
    InitStack(&S);
    StackEmpty(S);
    Push(&S,1);
    Push(&S,2);
    Push(&S,3);
    Push(&S,4);
    Push(&S,5);
    GetTop(S,&e);
    Pop(&S,&e);
    GetTop(S,&e);

}
