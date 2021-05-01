#include <stdio.h>
#define ListSize 200
typedef int DataType;
#include "SeqList.h"


void MergeList(SeqList A, SeqList B, SeqList *C);


int main() {
    DataType a[] = {3,5,6,7,11,15,23,45};
    DataType b[] = {1,4,7,11,15,19,21,25,34,46,57,68};
    SeqList A, B, C;
    InitList(&A);
    InitList(&B);
    InitList(&C);

    for (int i = 1; i <= sizeof(a) / sizeof(a[0]); i++) {
        if (InsertList(&A, i, a[i-1]) == 0) {
            printf("位置不合法。");
            return -1;
        }
    }

    for (int i = 1; i <= sizeof(b) / sizeof(b[0]); i++) {
        if (InsertList(&B, i, b[i-1]) == 0) {
            printf("位置不合法。");
            return -1;
        }
    }

    printf("顺序表A中的元素是：\n");
    ListPrint(A);

    printf("顺序表B中的元素是：\n");
    ListPrint(B);

    MergeList(A, B, &C);

    printf("合并后顺序表C中的元素是：\n");
    ListPrint(C);
}


void MergeList(SeqList A, SeqList B, SeqList *C) {
    int i, j, k;
    i = j =k =1;
    DataType e1, e2;

    while (i <= A.length && j <= B.length) {
        GetElem(A, i, &e1);
        GetElem(B, j, &e2);
        if (e1 <= e2) {
            InsertList(C, k, e1);
            i++;
            k++;
        } else {
            InsertList(C, k, e2);
            j++;
            k++;
        }
    }

    while (i <= A.length) {
        GetElem(A, i, &e1);
        InsertList(C, k, e1);
        i++;
        k++;
    }

    while (j <= B.length) {
        GetElem(B, j, &e2);
        InsertList(C, k, e2);
        j++;
        k++;
    }

    C->length = A.length + B.length;
}
