#include <stdio.h>
#define ListSize 200
typedef int DataType;
#include "SeqList.h"


void UnionAB(SeqList *A, SeqList B);


int main() {
    int i, flag;
    DataType e;
    DataType a[] = {12,34,56,34,87,43,23};
    DataType b[] = {12,333,444,555,666,777,23};
    SeqList LA, LB;
    InitList(&LA);
    InitList(&LB);

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
    for (i = 1; i <= LA.length; i++) {
        flag = GetElem(LA, i, &e);

        if (flag == 1)
            printf("%4d", e);
    }
    printf("\n");


    printf("顺序表LB中的元素:\n");
    for (i = 1; i <= LB.length; i++) {
        flag = GetElem(LB, i, &e);

        if (flag == 1)
            printf("%4d", e);
    }
    printf("\n");


    printf("将LB中不在LA中的元素插入LA中。\n");

    UnionAB(&LA, LB);

    printf("新的顺序表LA中的元素:\n");
    for (i = 0; i <= LA.length; i++) {
        flag = GetElem(LA, i, &e);

        if (flag == 1)
            printf("%4d", e);
    }
    printf("\n");
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
