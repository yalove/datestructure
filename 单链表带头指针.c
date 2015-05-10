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

//������ͷָ�뵥����
int CreatList_L(LinkList *L,int n) //???ָ���ָ�룿����
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
        printf("��%d��Ԫ����%d\n",i,p->data);
        printf("��%d��Ԫ�صĵ�ַ��%p\n",i,p);
        p->next = (*L)->next;
        (*L)->next =p;
    }
    printf("L�ĵ�ַ��%p\n",&L);
    printf("L�ĵ�ַ��%p\n",L);
    printf("L->NEXT�ĵ�ַ��%p\n",(*L)->next);

    return 0;
}
//����Ԫ��
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
//ɾ��Ԫ��
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
//��ȡ��
int GetLength_L(LinkList L)
{
    int i=0;
    LinkList p=L->next;
    while(p){
        p=p->next;
        i++;
    }
    printf("����%d\n",i);
}
//��ȡ����Ԫ��
int GetAllElem_L(LinkList L)
{
    printf("L->NEXT�ĵ�ַ��%p\n",L->next);
    LinkList p =L->next;
    int i=1;
    while(p){
        printf("��%d��Ԫ���ǣ�%d\n",i,p->data);
        p=p->next;
        i++;
    }
}

//��ȡĳ��Ԫ��
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
    printf("��%d��Ԫ����%d\n",i,*e);
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
