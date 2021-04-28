#include <stdio.h>
#define ListSize 200
typedef int DataType;
#include "SeqList.h"


void SplitSeqList(SeqList *L);


int main() {
    int i, flag;
    DataType e;
    SeqList L;

    int a[] = {88, -9, -28, 19,-31, 22, -50, 62, -76};

    InitList(&L);
    for (i = 1; i <= sizeof(a) / sizeof(a[0]); i++) {
        if (InsertList(&L, i, a[i-1]) == 0) {
            printf("位置不合法。\n");
            return -1;
        }
    }

    printf("顺序表L中的元素：\n");
    for (i=1; i <= L.length; i++) {
        flag = GetElem(L, i, &e);

        if (flag == 1)
            printf("%4d", e);
    }
    printf("\n");

    printf("顺序表L调整顺序后：\n");

    SplitSeqList(&L);

    printf("顺序表L中的元素：\n");
    for (i=1; i <= L.length; i++) {
        flag = GetElem(L, i, &e);

        if (flag == 1)
            printf("%4d", e);
    }
    printf("\n");

    return 0;
}


void SplitSeqList(SeqList *L) {
    int i, j;
    DataType e;
    i = 0, j=(*L).length-1;

    while (i < j) {
        while (L->list[i] <= 0)
            i++;
        while (L->list[j] > 0)
            j--;

        if (i < j) {
            e = L->list[i];
            L->list[i] = L->list[j];
            L->list[j] = e;
        }
    }
}
