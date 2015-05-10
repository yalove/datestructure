#include<stdio.h>
#include<stdlib.h>

#define LIST_INIT_SIZE 2
#define LISTINCREMENT 2

typedef int ElemType;
typedef int Status;

typedef struct
{
    ElemType * elem;
    int length;
    int listsize;
}SqList;

//(*L)『这是结构体本身』.elem 等同于 L『这是指针类型结构体』->elem
Status InitList_Sq(SqList * L)
{   //初始化空表
    //L引用一片区域类型为SeqList,malloc动态增加区域返回一个地址，这个地址被强制转换为Elemtype型；
    //结构L中的elem为首元素的地址即一个指针
    (*L).elem =(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));

    //看看L的首地址和现在保存的内容
    int *z;
    z = (*L).elem;
    printf("地址=%p , 地址=%p\n",z,*z);

    if(!(*L).elem)
    {
        exit(0);
    }
    (*L).length = 0;
    (*L).listsize = LIST_INIT_SIZE;
    return 1;
}

Status Listlength_Sq(SqList L)//这里不需要引用，直接查看L和L的元素；在需要进行更改L中元素时最好进行引用
{
    if(!L.elem)
    {
        exit(0);
    }
    printf("Listlength=%d\n",L.length);
}

Status ClearList(SqList *L)//这里进行引用，如果不引用，只能改变函数内的length不能改变函数外L的length
{   //将length置0，elem元素的值仍然存在，但通过GetElem_Sq的方法不能访问到，只能直接访问L.elem[i]
    if(!(*L).elem)
    {
        exit(0);
    }
    (*L).length = 0;
    return 1;
}

Status DestoryList_Sq(SqList *L)
{   //释放内存空间，free(指针)
    free((*L).elem);
}

Status length_Sq(SqList L)
{
    if(!L.elem)
    {
        exit(0);
    }
    return L.length;
}

Status GetElem_Sq(SqList L,int i)
{
    if(i<1 || i>L.length)
    {
        exit(0);
    }
    printf("List[%d]=%d\n",i, L.elem[i-1]);
}

Status GetListM_Sq(SqList L)
{
    //取表中所有元素，这里可以看看每个元素的地址和元素的值
    if(!L.elem)
    {
        exit(0);
    }
    int i;
    for(i=1;i<=L.length;i++)
    {
        printf("List[%d]=%d，地址=%p\n",i,L.elem[i-1],&L.elem[i-1]);
    }
}

Status ListInsert_Sq(SqList *L,int i ,ElemType e)
{
    if(i<1 || i>(*L).length+1)
    {
        return 0;
    }
    if((*L).length>=(*L).listsize)
    {
        ElemType *newbase;
        newbase = (ElemType*)realloc((*L).elem,((*L).listsize+LISTINCREMENT)*sizeof(ElemType));
        if(!newbase)
        {
            return 0;
        }
        (*L).elem = newbase;
        (*L).listsize +=LISTINCREMENT;
    }
    ElemType *q ,*p;
    q = &(*L).elem[i-1];
    p=&(*L).elem[(*L).length-1];
    for(p;p>=q;--p)
    {
        *(p+1)=*p;
    }
    *q=e;
    ++(*L).length;
    return 1;
}

Status ListDelete_Sq(SqList *L,int i,ElemType *e)
{
    if(i<1 ||i>(*L).length)
    {
        return 0;
    }
    ElemType *p,*q;
    p = &(*L).elem[i-1];
    (*e)= *p;
    q=(*L).elem+(*L).length-1;
    for(++p;p<=q;++p)
    {
        *(p-1)=*p;
    }
    --(*L).length;
    printf("Delete L.elem[%d]=%d\n",i,(*e));
    return 1;
}

int main()
{
    printf("int类型的大小=%d\n",sizeof(int));
    SqList L;
    InitList_Sq(&L);
    ListInsert_Sq(&L,1,1);
    ListInsert_Sq(&L,1,2);
    ListInsert_Sq(&L,1,3);
    ListInsert_Sq(&L,1,4);
    ListInsert_Sq(&L,1,5);
    GetListM_Sq(L);

}

//int main()
//{
//  SqList L;
//    InitList_Sq(&L);
//    printf("elem----%p\n",L.elem);
//   ListInsert_Sq(&L,1,0);
//    ListInsert_Sq(&L,1,1);
//    ListInsert_Sq(&L,1,2);
//    ListInsert_Sq(&L,1,3);
//    ListInsert_Sq(&L,1,4);
 //   GetListM_Sq(L);
//    GetElem_Sq(L,2);
 //   ClearList(&L);
  //  GetListM_Sq(L);

 //   SqList L1;
 //   InitList_Sq(&L1);
//    ListInsert_Sq(&L1,1,00);
//    ListInsert_Sq(&L1,1,10);
 //   ListInsert_Sq(&L1,1,20);
//    ListInsert_Sq(&L1,1,30);
//    ListInsert_Sq(&L1,1,40);
 //   GetListM_Sq(L1);
//    ListDelete_Sq(&L1,2,1);
//    GetListM_Sq(L1);

 //   DestoryList_Sq(&L1);
 //   GetListM_Sq(L1);
//}
