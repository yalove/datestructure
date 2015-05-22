#include <stdio.h>
#include <stdlib.h>

#define ERROR -2
#define OVERFLOW 2
#define true 1
#define false 0

#define STACK_INIT_SIZE 10
#define STACK_SIZE 5

typedef int ElemType;

typedef struct
{
    ElemType *base;
    ElemType *top;
    int stacksize;
}SqStack;

//初始化一个空栈S
int InitStack(SqStack *S)
{
    S->base = malloc(STACK_INIT_SIZE*sizeof(ElemType));
    if(!S->base) exit(OVERFLOW);
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return true;
}

//判断栈是否空，空返回true
int StackEmpty(SqStack S)
{
    if(!S.base) exit(OVERFLOW);
    if(S.top==S.base){
        return true;
    }
    else
        return false;
}

//进栈，若栈未满
int Push(SqStack *S,ElemType e)
{
    if(S->top-S->base==S->stacksize){
        S->base =realloc(S->base,(S->stacksize+STACK_SIZE)*sizeof(ElemType));
        if(!S->base) exit(OVERFLOW);
        S->stacksize+=STACK_SIZE;
    }
    S->top++;
    *S->top =e;
    //e=*(S->top++);
    //printf("s->top=%d\n",*S->top);
    return true;
}

//出栈，若栈不为空
int Pop(SqStack *S,ElemType *e)
{
    if(!StackEmpty(*S)){
        *e = *S->top;
        S->top--;
        //*e =*(S->top--);
    }
    return true;
}

//读栈顶元素，并返回元素
int GetTop(SqStack S,ElemType *e)
{
    if(!StackEmpty(S)){
        *e =*S.top;
        printf("top=%d\n",*e);
    }
    return true;
}

//销毁栈，释放栈占用的空间
int DestoryStack(SqStack S)
{
    if(!S.base) exit(ERROR);
    free(S.base);
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
    StackEmpty(S);
    GetTop(S,&e);
    Pop(&S,&e);
    printf("del=%d\n",e);
    Pop(&S,&e);
    printf("del=%d\n",e);
    Pop(&S,&e);
    printf("del=%d\n",e);
    Pop(&S,&e);
    DestoryStack(S);
    GetTop(S,&e);


}
