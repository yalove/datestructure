#include <stdio.h>
#include <stdlib.h>

#define ERROR -2
#define OVERFLOW 2
#define true 1
#define false 0
#define maxsize 4

/*/
队列的顺序存储会发生假溢出的问题，数组中还可以容纳元素，但队列已经到了数组最尾部
因此考虑循环队列
顺序存储的关键在于 队列入队和出队的条件判断上
/*/
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
    if(Q.front==Q.rear==0) return true;
    else return false;
}

//入队，若队列未满，e加入成为队尾
//怎么判断队列未满，队列满的情况下不能加入元素
int EnQueue(SqQueue *Q,ElemType e)
{
    if(Q->rear<=maxsize){
        Q->data[Q->rear++]=e;
    }
    printf("Q=%d,front=%d,rear=%d\n",e,Q->front,Q->rear);
    return true;
}

//出队，若队列不为空，删除队头元素并用e返回
int DeQueue(SqQueue *Q,ElemType *e)
{
    if(Q->front<Q->rear){
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
    GetHead(Q,&e);
    EnQueue(&Q,4);//多加入一个元素不知道为什么front的值改变了
    GetHead(Q,&e);
    DeQueue(&Q,&e);
    GetHead(Q,&e);
    DeQueue(&Q,&e);
    GetHead(Q,&e);
    DeQueue(&Q,&e);
    GetHead(Q,&e);
    DeQueue(&Q,&e);
    GetHead(Q,&e);

}
