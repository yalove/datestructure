#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
#define OVERFLOW 1


typedef int ElemType ;

typedef struct node
{
    ElemType data;
    struct node *next;
}LNode ,*LinkList;

创建带头指针单链表
逆序存储，第一个输入的数据在表末尾
int CreatList_L(LinkList *L,int n) //???指针的指针？？？
{
    (*L)=(LinkList)malloc(sizeof(LinkList));
    if(!L){
        exit(OVERFLOW);
    }
    (*L)->next = NULL;
    int i;
    for(i=n;i>0;i--){
        LinkList p =(LinkList)malloc(sizeof(LinkList));
        scanf("%i",&(p->data));
        printf("第%d个元素是%d\n",i,p->data);
        printf("第%d个元素的地址是%p\n",i,p);
        p->next = (*L)->next;
        (*L)->next =p;
    }
    printf("L的地址是%p\n",&L);
    printf("L的地址是%p\n",L);
    printf("L->NEXT的地址是%p\n",(*L)->next);

    return 0;
}

//顺序存储数据，第一个输入的数据中表首
//int CreatList_L(LinkList *L,int n)
//{
//    (*L)=(LinkList)malloc(sizeof(LinkList));
//    if(!L){
//        exit(OVERFLOW);
//    }
//    int i;
//    for(i=0;i<n;i++){
//        LinkList p=(LinkList)malloc(sizeof(LinkList));
//        scanf("%i",&(p->data));
//        (*L)->next = p;
//        p->next =NULL;
//        printf("第%d个元素是:%d\n",i+1,p->data);
//    }
//}


//插入元素
int ListInsert_L(LinkList *L,int i,ElemType e)
{
    if(!L) exit(OVERFLOW);
    LinkList p =(*L)->next;
    int j=1;
    while(p&&j<i-1){
        p=p->next;
        ++j;
    }
    if(!p||j>i-1) return ERROR;
    LinkList s=(LinkList)malloc(sizeof(LinkList));
    s->data =e;
    s->next = p->next;
    p->next = s;
}
//删除元素
int ListDelete_L(LinkList *L,int i, ElemType *e)
{
    if(!L) exit(OVERFLOW);
    LinkList p =(*L)->next;
    int j=1;
    while(p&&j<i-1){
        p=p->next;
        ++j;
    }
    if(!p||j>i-1) return ERROR;
    LinkList q = p->next;
    p->next = q->next;
    *e =p->data;
    free(q);


}
//获取表长
int GetLength_L(LinkList L)
{
    int i=0;
    LinkList p=L->next;
    while(p){
        p=p->next;
        i++;
    }
    printf("表长：%d\n",i);
}
//获取所有元素
int GetAllElem_L(LinkList L)
{
    printf("L->NEXT的地址是%p\n",L->next);
    LinkList p =L->next;
    int i=1;
    while(p){
        printf("第%d个元素是：%d\n",i,p->data);
        p=p->next;
        i++;
    }
}

//获取某个元素
int GetElem_L(LinkList L,int i,ElemType *e)
{
    LinkList p=L->next;
    int j=1;
    while(p&&j<i){
        p=p->next;
        ++j;
    }
    if(!p||j>i) return ERROR;
    *e= p->data;
    printf("第%d个元素是%d\n",i,*e);
    return *e;

}
int main()
{
    ElemType e;
    LinkList L;
    CreatList_L(&L,5);
    //GetElem_L(L,1,&e);
    GetAllElem_L(L);
    ListInsert_L(&L,6,33);
    GetAllElem_L(L);
    ListDelete_L(&L,3,&e);
    GetAllElem_L(L);
    GetLength_L(L);

}
