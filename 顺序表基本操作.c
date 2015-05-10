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

//(*L).elem ��ͬ�� L->elem
Status InitList_Sq(SqList * L)
{   //��ʼ���ձ�
    //L����һƬ��������ΪSeqList,malloc��̬�������򷵻�һ����ַ�������ַ��ǿ��ת��ΪElemtype�ͣ�
    //�ṹL�е�elemΪ��Ԫ�صĵ�ַ��һ��ָ��
    (*L).elem =(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));

    //����L���׵�ַ�����ڱ��������
    int *z;
    z = (*L).elem;
    printf("��ַ=%p , ��ַ=%p\n",z,*z);

    if(!(*L).elem)
    {
        exit(0);
    }
    (*L).length = 0;
    (*L).listsize = LIST_INIT_SIZE;
    return 1;
}

Status Listlength_Sq(SqList L)//���ﲻ��Ҫ���ã�ֱ�Ӳ鿴L��L��Ԫ�أ�����Ҫ���и���L��Ԫ��ʱ��ý�������
{
    if(!L.elem)
    {
        exit(0);
    }
    printf("Listlength=%d\n",L.length);
}

Status ClearList(SqList *L)//����������ã���������ã�ֻ�ܸı亯���ڵ�length���ܸı亯����L��length
{   //��length��0��elemԪ�ص�ֵ��Ȼ���ڣ���ͨ��GetElem_Sq�ķ������ܷ��ʵ���ֻ��ֱ�ӷ���L.elem[i]
    if(!(*L).elem)
    {
        exit(0);
    }
    (*L).length = 0;
    return 1;
}

Status DestoryList_Sq(SqList *L)
{   //�ͷ��ڴ�ռ䣬free(ָ��)
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
    //ȡ��������Ԫ�أ�������Կ���ÿ��Ԫ�صĵ�ַ��Ԫ�ص�ֵ
    if(!L.elem)
    {
        exit(0);
    }
    int i;
    for(i=1;i<=L.length;i++)
    {
        printf("List[%d]=%d����ַ=%p\n",i,L.elem[i-1],&L.elem[i-1]);
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
    printf("int���͵Ĵ�С=%d\n",sizeof(int));
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

