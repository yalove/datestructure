#include <stdio.h>
#include <stdlib.h>


#define ERROR -2
#define OVERFLOW 2
#define true 1
#define false 0

typedef char ElemType;

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

int CreatBiTree(BiTree *T)
{
    ElemType ch,temp;

    scanf("%c",&ch);
    temp=getchar();

    if(ch==' ')
    {
        *T=NULL;
    }
    else
    {
        *T=malloc(sizeof(BiTNode));
        if(!*T) exit(ERROR);
        (*T)->data=ch;
        printf("输入%c的左子结点：\n",ch);
        CreatBiTree(&(*T)->lchild);
        printf("输入%c的右子结点：\n",ch);
        CreatBiTree(&(*T)->rchild);
    }
    return true;
}

int main()
{
    BiTree T;
    CreatBiTree(&T);
}
