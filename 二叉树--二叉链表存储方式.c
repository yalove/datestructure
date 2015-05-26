#include <stdio.h>
#include <stdlib.h>


#define ERROR -2
#define OVERFLOW 2
#define true 1
#define false 0



typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef BiTree ElemType;

//使用栈来非递归遍历树结构
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
int isEmpty(LiStack S)
{
    if(S->next==NULL)
    {
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
    return true;
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
int GetTop(LiStack *S,ElemType *e)
{
    if(!S){
        return ERROR;
    }
    else if(!(*S)->next){
        return ERROR;
    }
    else{
        *e = (*S)->next->data;
    }
    return true;
}

//使用队列来进行层次遍历
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
int QisEmpty(LinkQueue Q)
{
    if(Q.front==Q.rear)
    {
         return true;
    }
    return false;
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

//创建二叉树
//按先序顺序输入元素，空格表示空树
int CreatBiTree(BiTree *T)
{
    char ch;
    scanf("%c",&ch);
    if(ch=='#')
    {
        (*T)=NULL;
    }
    else
    {
        (*T)=malloc(sizeof(BiTNode));
        if((*T)==NULL){
            exit(OVERFLOW);
        }
        (*T)->data=ch;
        CreatBiTree(&((*T)->lchild));
        CreatBiTree(&((*T)->rchild));
    }
    return true;
}

//二叉树的建立方法二
//这个方法不知道怎么还有点问题
//问题解决。。函数调用的问题
BiTree CreatBiTree2(BiTree t)
{
    char ch;
    scanf("%c",&ch);

    if(ch=='#')
    {
        t=NULL;
    }
    else
    {
        t=malloc(sizeof(BiTNode));
        if(t==NULL) exit(ERROR);
        t->data=ch;
        t->lchild=CreatBiTree2(t->lchild);
        t->rchild=CreatBiTree2(t->rchild);
    }
    return t;
}


//前序递归遍历
int PreOrderTraverse(BiTree T)
{
    if(T!=NULL)
    {
        printf("%c",T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
    return true;
}

//前序非递归遍历
int NoPreOrderTraverse(BiTree T)
{
    LiStack S;
    InitStack(&S);

    BiTree tmp=T;
    if(tmp==NULL)
    {
        exit(ERROR);
    }
    while((tmp!=NULL)||(isEmpty(S)!=true))
    {
        while(tmp!=NULL)
        {
            Push(&S,tmp);
            printf("%c",tmp->data);
            tmp=tmp->lchild;
        }
        if(isEmpty(S)!=true)
        {
            Pop(&S,&tmp);
            tmp=tmp->rchild;
        }
    }
    return true;
}


//中序递归遍历
int InOrderTraverse(BiTree T)
{
    if(T!=NULL)
    {
        InOrderTraverse(T->lchild);
        printf("%c",T->data);
        InOrderTraverse(T->rchild);
    }
    return true;
}

//中序非递归遍历
int NoInOrderTraverse(BiTree T)
{
    LiStack S;
    InitStack(&S);

    BiTree tmp=T;
    if(tmp==NULL)
    {
        exit(ERROR);
    }
    while(tmp!=NULL||(isEmpty(S)!=true))
    {
        while(tmp!=NULL)
        {
            Push(&S,tmp);
            tmp=tmp->lchild;
        }
        if(isEmpty(S)!=true)
        {
            Pop(&S,&tmp);
            printf("%c",tmp->data);
            tmp=tmp->rchild;
        }
    }
    return true;
}
//后序递归遍历
int PostOrderTraverse(BiTree T)
{
    if(T!=NULL)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%c",T->data);
    }
    return true;
}

//后序非递归遍历
int NoPostOrderTraverse(BiTree T)
{
    LiStack S;
    InitStack(&S);

    BiTree tmp;
    BiTree cur;
    BiTree pre=NULL;

    if(T==NULL)
    {
        exit(ERROR);
    }
    Push(&S,T);
    while(isEmpty(S)!=true)
    {
        GetTop(&S,&cur);
        if((cur->lchild==NULL&&cur->rchild==NULL)||(pre!=NULL&&(pre==cur->lchild||pre==cur->rchild)))
        {
            printf("%c",cur->data);
            Pop(&S,&tmp);
            pre=cur;
        }
        else
        {
            if(cur->rchild!=NULL)
            {
                Push(&S,cur->rchild);
            }
            if(cur->lchild!=NULL)
            {
                Push(&S,cur->lchild);
            }
        }
    }
    return true;

}

//二叉树广度遍历--即层次遍历
//使用队列来实现
int TraverseBiTree(BiTree T)
{
    LinkQueue Q;
    InitQueue(&Q);

    BiTree tmp=T;
    if(tmp==NULL)
    {
        exit(ERROR);
    }
    EnQueue(&Q,tmp);
    while(QisEmpty(Q)!=true)
    {
        DeQueue(&Q,&tmp);
        printf("%c",tmp->data);
        if(tmp->lchild!=NULL)
        {
            EnQueue(&Q,tmp->lchild);
        }
        if(tmp->rchild!=NULL)
        {
            EnQueue(&Q,tmp->rchild);
        }
    }
    return true;
}

//二叉树的深度
//最大层次即为深度
//递归求深度
int BiTreeDeep(BiTree T)
{
    int dept=0;
    if(T)
    {
        int lchilddept=BiTreeDeep(T->lchild);
        int rchilddept=BiTreeDeep(T->rchild);
        dept=lchilddept>=rchilddept?(lchilddept+1):(rchilddept+1);
    }
    printf("D=%d\n",dept);
    return dept;

}

//非递归求深度
int NoBiTreeDeep(BiTree T)
{
    LinkQueue q;
    InitQueue(&q);

    BiTree tmp=T;
    if(tmp==NULL) exit(ERROR);
    EnQueue(&q,tmp);
    while(QisEmpty(q)!=true)
    {
        DeQueue(&q,&tmp);
        // printf("%c",tmp->data);
        if(tmp->lchild!=NULL)
        {
            EnQueue(&q,tmp->lchild);
        }
        if(tmp->rchild!=NULL)
        {
            EnQueue(&q,tmp->rchild);
        }
    }
    int deep=0;
    BiTree m=tmp;
    BiTree n=T;
    while(m!=n)
    {
        EnQueue(&q,n);
        while(QisEmpty(q)!=true)
        {
            DeQueue(&q,&tmp);
            if(m==tmp->lchild||m==tmp->rchild)
            {
                deep++;
                m=tmp;
                break;
            }
            if(tmp->lchild!=NULL)
            {
                EnQueue(&q,tmp->lchild);
            }
            if(tmp->rchild!=NULL)
            {
                EnQueue(&q,tmp->rchild);
            }
        }
    }
    printf("Deep=%d\n",deep+1);
}

//查找结点
BiTree Locate(BiTree T)
{

}

//判断两棵树是否相同
int isEqual(BiTree t1,BiTree t2)
{

}

int main()
{
    BiTree T;
    printf("创建二叉链表，请按先序连续输入树元素\n");
    CreatBiTree(&T);
    printf("PRE--Order\n");
    PreOrderTraverse(T);
    printf("\n");
    printf("IN--Order\n");
    InOrderTraverse(T);
    printf("\n");
    printf("POST--Order\n");
    PostOrderTraverse(T);
    printf("\n");
    printf("NoPre--Order\n");
    NoPreOrderTraverse(T);
    printf("\n");
    printf("NoIN--Order\n");
    NoInOrderTraverse(T);
    printf("\n");
    printf("NoPOST--Order\n");
    NoPostOrderTraverse(T);
    printf("\n");
    printf("Traverse\n");
    TraverseBiTree(T);
    BiTreeDeep(T);
    NoBiTreeDeep(T);


    printf("方法2创建树\n");
    BiTree t;
    t=CreatBiTree2(t);
    PreOrderTraverse(t);

}
