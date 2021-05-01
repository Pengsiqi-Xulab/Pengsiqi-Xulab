#include <stdio.h>
#define ListSize 200
typedef int DataType;
#include "SeqList.h"


void UnionAB(SeqList *A, SeqList B);

void UnionABElem(SeqList LA, SeqList LB, SeqList *LC);

void DelElem(SeqList *A, SeqList B);

int main() {
    int i;
    DataType a[] = {12,34,56,34,87,43,23};
    DataType b[] = {12,333,444,555,666,777,23};
    SeqList LA, LB, LC;
    InitList(&LA);
    InitList(&LB);
    InitList(&LC);

    for (i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        if (InsertList(&LA, i+1, a[i]) == 0) {
            printf("位置不合法\n");
            return -1;
        }
    }

    for (i = 0; i< sizeof(b) / sizeof(b[0]); i++) {
        if (InsertList(&LB, i+1, b[i]) == 0) {
            printf("位置不合法\n");
            return -1;
        }
    }

    printf("顺序表LA中的元素:\n");
    ListPrint(LA);


    printf("顺序表LB中的元素:\n");
    ListPrint(LB);

    UnionABElem(LA, LB, &LC);

    printf("顺序表LA,LB的差集合：LC中的元素:\n");
    ListPrint(LC);

    printf("将LB中不在LA中的元素插入LA中。\n");
    UnionAB(&LA, LB);

    printf("新的顺序表LA中的元素:\n");
    ListPrint(LA);

    printf("删除LA中和LB重复的元素。\n");

    DelElem(&LA, LB);

    printf("新的顺序表LA中的元素:\n");
    ListPrint(LA);

    return 0;
}


void UnionAB(SeqList *LA, SeqList LB) {
    int i, flag, pos;
    DataType e;

    for (i = 1; i <= LB.length; i++) {
        flag = GetElem(LB, i, &e);

        if (flag == 1) {
            pos = LocateElem(*LA, e);


        if (!pos)
            InsertList(LA, LA->length+1, e);
        }
    }
}


void UnionABElem(SeqList LA, SeqList LB, SeqList *LC) {
    int i, flag, pos;
    DataType e;

    for (i = 1; i <= LB.length; i++) {
        flag = GetElem(LB, i, &e);

        if (flag == 1) {
            pos = LocateElem(LA, e);


        if (!pos)
            InsertList(LC, LC->length+1, e);
        }
    }
}


void DelElem(SeqList *A, SeqList B) {
    int i, flag, pos;
    DataType e;
    for (i =1; i <= B.length; i++) {
        flag = GetElem(B, i, &e);

        if (flag == 1) {
            pos = LocateElem(*A, e);

            if (pos > 0)
                DeletList(A, pos);
        }
    }
}
