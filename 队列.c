#include <stdio.h>
#include <stdlib.h>

#define ERROR -2
#define OVERFLOW 2
#define true 1
#define false 0
#define maxsize 10

typedef int ElemType;

//队列的顺序存储方式 数组的实现方式
typedef struct
{
    ElemType data[maxsize];
    int front,rear;
}SqQueue;

//初始化一个队列Q
int InitQueue(SqQueue *Q)
{
    Q->front=0;
    Q->rear =0;
    return true;
}

//判断队列是否空，空返回true
int QueueEmpty(SqQueue Q)
{
    if(Q.front==Q.rear) return true;
    else return false;
}

//入队，若队列未满，e加入成为队尾
int EnQueue(SqQueue *Q,ElemType e)
{
    if(Q->rear<maxsize-1){
        Q->data[Q->rear++]=e;
    }
    printf("Q=%d,front=%d,rear=%d\n",e,Q->front,Q->rear);
    return true;
}

//出队，若队列不为空，删除队头元素并用e返回
int DeQueue(SqQueue *Q,ElemType *e)
{
    if(Q->front<=Q->rear){
        *e=Q->data[Q->front++];
    }
    printf("Q=%d,front=%d,rear=%d\n",*e,Q->front,Q->rear);
    return true;
}

//获取队列第一个元素，若队列不为空
int GetHead(SqQueue Q,ElemType *e)
{
    if(Q.front<Q.rear){
        *e=Q.data[Q.front];
        printf("head=%d\n",*e);
    }
    return true;
}



int main()
{
    ElemType e;
    SqQueue Q;
    InitQueue(&Q);
    QueueEmpty(Q);
    EnQueue(&Q,1);
    EnQueue(&Q,2);
    GetHead(Q,&e);
    EnQueue(&Q,3);
    EnQueue(&Q,4);
    DeQueue(&Q,&e);
    DeQueue(&Q,&e);
    DeQueue(&Q,&e);

}
