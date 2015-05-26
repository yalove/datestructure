#include <stdio.h>
#include <stdlib.h>

#define ERROR -2
#define OVERFLOW 2
#define true 1
#define false 0

typedef int ElemType;


typedef struct LinkNode            //链式队列结点
{
    ElemType data;
    struct LinkNode *next;

}LinkNode;

typedef struct              //链式队列
{
    LinkNode *front ,*rear; //队列头尾指针
}LinkQueue;

//初始化带头结点，可以统一操作，简洁方便
int InitQueue(LinkQueue *Q)
{
    Q->front=Q->rear=malloc(sizeof(LinkNode));
    Q->front->next=NULL;
    return true;
}

//判读队空
int isEmpty(LinkQueue Q)
{
    if(Q.front==Q.rear) return true;
    else return false;
}

//入队
int EnQueue(LinkQueue *Q,ElemType e)
{
    LinkNode *p=malloc(sizeof(LinkNode));
    p->data =e;
    p->next =NULL;
    (Q->rear)->next=p;
    Q->rear=p;
    return true;
}

//出队
int DeQueue(LinkQueue *Q,ElemType *e)
{
	LinkNode *p;
    if(Q->front==Q->rear) return false;
    p=Q->front->next;
    *e=p->data;
    Q->front->next=p->next;
    if(Q->rear==p)
        Q->rear=Q->front;
    free(p);
    return true;
}

//获取队头元素
int GetQT(LinkQueue Q,ElemType *e)
{
	LinkNode *p;
    if(Q.front==Q.rear) return false;
    p =Q.front->next;
    *e=p->data;
    printf("QT=%d\n",*e);
    return true;
}

//获取队列所有元素
int GetALL(LinkQueue Q)
{
	LinkNode *s;
    int i=0;
    LinkNode *p =Q.front->next;
    while(p!=Q.rear->next){
        printf("Q[%d]=%d\n",i,p->data);
        i++;
        s=p;
        p=s->next;
    }
    return true;
}
int main()
{
    int i=0;
    ElemType e,x;
    LinkQueue Q;
    InitQueue(&Q);
    isEmpty(Q);
    for(i;i<5;i++){
        scanf("%d",&x);
        EnQueue(&Q,x);
    };
    GetQT(Q,&e);
    GetALL(Q);
    printf("出队两个元素-------\n");
    DeQueue(&Q,&e);
    DeQueue(&Q,&e);
    GetALL(Q);

}
