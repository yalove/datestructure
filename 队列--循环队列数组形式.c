#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
#define OVERFLOW 1
#define true 2
#define false -2
#define maxsize 10

typedef int ElemType;

//顺序栈 数组的实现方式
typedef struct
{
    ElemType data[maxsize];
    int top;
}SqQueue;
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
int Push(SqStack *S,ElemType X)
{
    if(S->top==maxsize-1){
        return false;
    }
    S->data[++S->top]=X;
    return true;
}

//出栈，若栈不为空
int Pop(SqStack *S,ElemType *X)
{
    if(S->top==-1){
        return false;
    }
    *X=S->data[S->top--];
    return true;
}

//读栈顶元素，并返回元素
int GetTop(SqStack S,ElemType *X)
{
    if(S.top==-1){
        return false;
    }
    *X=S.data[S.top];
    return *X;
}



int main()
{
    ElemType X;
    SqStack S;
    InitStack(&S);
    StackEmpty(S);
    Push(&S,1);
    Push(&S,2);
    Push(&S,3);
    Push(&S,4);
    Push(&S,5);
    GetTop(S,&X);
    Pop(&S,&X);
    GetTop(S,&X);

}
