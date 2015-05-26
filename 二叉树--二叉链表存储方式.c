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


}
