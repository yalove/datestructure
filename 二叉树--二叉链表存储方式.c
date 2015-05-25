#include <stdio.h>
#include <stdlib.h>

#define ERROR -2
#define OVERFLOW 2
#define true 1
#define false 0

typedef int ElemType;

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//创建二叉树
//按先序顺序输入元素，空格表示空树
int CreatBiTree(BiTree *T)
{
    char ch;
    scanf(&ch);
    if(ch==' ') (*T)=NULL;
    else{
        (*T)=malloc(sizeof(BiTNode));
        if(!(*T)) exit(OVERFLOW);
        (*T)->data=ch;
        CreatBiTree((*T)->lchild);
        CreatBiTree((*T)->rchild);
    }
    return true;
}

int main()
{
    BiTree T;
    CreatBiTree(&T);
}
