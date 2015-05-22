#include <stdio.h>
#include <stdlib.h>

#define ERROR -2
#define OVERFLOW 2
#define true 1
#define false 0

typedef int ElemType;

typedef struct Linknode
{
    ElemType data;
    struct Linknode *next;
}Linknode,*LiStack;
//初始化一个空栈S
int InitStack(LiStack *S)
{
    (*S)=malloc(sizeof(Linknode));
    if(!S) exit(OVERFLOW);
    (*S)->next =NULL;
    return true;
}

//判断栈是否空，空返回true
int StackEmpty(LiStack S)
{
    if(S->next==NULL){
            return true;
    }
    return false;
}

//进栈，栈不会满
int Push(LiStack *S,ElemType e)
{
    Linknode *p;
    p =malloc(sizeof(Linknode));
    p->data = e;
    //printf("p->data=%d\n",p->data);
    p->next = (*S)->next;
    (*S)->next = p;
}

//出栈，若栈不为空
int Pop(LiStack *S,ElemType *e)
{
    Linknode *q;
    if((*S)->next==NULL) exit(ERROR);
    q=(*S)->next;
    *e=q->data;
    (*S)->next=q->next;
    free(q);
    return true;
}

//读栈顶元素，并返回元素
int GetTop(LiStack S,ElemType *e)
{
    if(S->next){
        *e = S->next->data;
    }
    printf("top=%d\n",*e);
    printf("---------\n");
    return true;
}

//销毁栈，释放栈占用的空间
int DestoryStack(LiStack S)
{
    Linknode *q;
    while(!S->next){
        q=S->next;
        S->next=q->next;
        free(q);
    }
    free(S);
}

int main()
{
    ElemType e;
    //printf("top=%d\n",e);
    LiStack S;
    InitStack(&S);
    GetTop(S,&e);
    StackEmpty(S);
    Push(&S,1);
    Push(&S,2);
    Push(&S,3);
    StackEmpty(S);
    GetTop(S,&e);
    Pop(&S,&e);
    //printf("pop=%d\n",e);
    GetTop(S,&e);
    DestoryStack(S);
    GetTop(S,&e);

}
