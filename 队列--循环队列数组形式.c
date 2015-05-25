#include <stdio.h>
#include <stdlib.h>

#define ERROR -2
#define OVERFLOW 2
#define true 1
#define false 0
#define MaxSize 5

typedef int ElemType;

//循环队列 数组的实现方式
typedef struct
{
    ElemType data[MaxSize];
    int front,rear;
}SqQueue;

//初始化队列
int InitQueue(SqQueue *Q)
{
    Q->front=0;
    Q->rear=0;
    return true;
}

//判断队空
int isEmpty(SqQueue Q)
{
    if(Q.rear==Q.front) return true;
    else return false;
}

//入队
int EnQueue(SqQueue *Q,ElemType e)
{
    if((Q->rear+1)%MaxSize==Q->front) return false;
    Q->data[Q->rear]=e;
    Q->rear=(Q->rear+1)%MaxSize;
    return true;
}

//出队
int DeQueue(SqQueue *Q,ElemType *e)
{
    if(Q->rear==Q->front) return false;
    *e=Q->data[Q->front];
    Q->front =(Q->front+1)%MaxSize;
    return true;
}

//获取队列第一个元素
int GetQT(SqQueue Q,ElemType *e)
{
    if(Q.rear==Q.front) return false;
    *e=Q.data[Q.front];
    return true;
}
//队列长度
int length_Q(SqQueue Q)
{
    printf("Length=%d\n",(Q.rear-Q.front+MaxSize)%MaxSize);
}

//获取队列所有元素
//由于为了区分队空还是队满，牺牲了一个单元，入队时少用了一个队列单元
//队头指针在队尾指针的下一位置作为队满地标志，所以 队列的元素是 maxsize-1
int GetALL(SqQueue Q)
{
    int j=Q.front;
    int m=0;
    if(Q.rear==Q.front) return false;
    if(j<=Q.rear){
        for(j;j<Q.rear;j++){
            printf("Q[%d]=%d\n",j,Q.data[j]);
        };
    }
    else {
        for(j;j<MaxSize;j++){
            printf("Q[%d]=%d\n",j,Q.data[j]);
        };
        for(m;m<Q.rear;m++){
            printf("Q[%d]=%d\n",m,Q.data[m]);
        };

    };
    return true;
}
int main()
{
    int i=0;
    SqQueue Q;
    ElemType e,x;
    InitQueue(&Q);
    isEmpty(Q);
    while(i<MaxSize-1){
        scanf("%d",&x);
        EnQueue(&Q,x);
        i++;
        GetQT(Q,&e);
    };
    GetALL(Q);
    DeQueue(&Q,&e);
    DeQueue(&Q,&e);
    printf("----出队两次----\n");
    GetALL(Q);
    printf("----入队两次----\n");
    EnQueue(&Q,5);
    EnQueue(&Q,6);
    GetALL(Q);
    length_Q(Q);



}
