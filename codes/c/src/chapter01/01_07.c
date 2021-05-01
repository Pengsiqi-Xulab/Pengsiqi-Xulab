#include <stdio.h>
// #include <malloc.h>
#include <stdlib.h>
typedef int DataType;
#include "LinkList.h"

void SortList(LinkList S);

ListNode *Append(ListNode *last, DataType e);

ListNode *Difference(ListNode *A, ListNode *B);

void ListPrint(LinkList A);


int main() {
    int i;
    DataType a[] = {22 ,7, 15, 56, 89, 38, 44, 65, 109, 83};
    DataType b[] = {15, 9, 22, 89, 33, 65, 90, 83};
    LinkList A, B, C;
    // ListNode *p;
    InitList(&A);
    InitList(&B);

    for (i = 1; i <= sizeof(a) / sizeof(a[0]); i++) {
        if (InsertList(A, i, a[i-1]) == 0) {
            printf("插入位置不合法。\n");
            return -1;
        }
    }

    for (i = 1; i <= sizeof(b) / sizeof(b[0]); i++) {
        if (InsertList(B, i, b[i-1]) == 0) {
            printf("插入位置不合法。\n");
            return -1;
        }
    }

    printf("A单链表");
    ListPrint(A);
    printf("B单链表");
    ListPrint(B);

    SortList(A);
    SortList(B);

    printf("排序后，\n");
    printf("A单链表");
    ListPrint(A);
    printf("B单链表");
    ListPrint(B);

    C = Difference(A, B);

    printf("A-B做差集后");
    printf("C单链表");
    ListPrint(C);

    return 0;
}


void SortList(LinkList S) {
    ListNode *p, *q, *r;
    DataType t;
    p = S->next;

    while (p->next) {
        r = p;
        q = p->next;

        while (q) {
            if (r->data > q->data)
                r = q;
            q = q->next;
        }

        if (p != r) {
            t = p->data;
            p->data = r->data;
            r->data =t;
        }
        p = p->next;
    }
}


ListNode *Append(ListNode *last, DataType e) {
    last->next = (ListNode*)malloc(sizeof(ListNode));
    last->next->data = e;
    return last->next;
}


ListNode *Difference(ListNode *A, ListNode *B) {
    ListNode *C, *last;
    C = last = (ListNode*)malloc(sizeof(ListNode));

    while (A != NULL && B != NULL)
        if (A->data < B->data) {
            last = Append(last, A->data);
            A = A->next;
        } else if (A->data == B->data) {
            A = A->next;
            B = B->next;
        } else
            B = B->next;

    while (A != NULL) {
        last = Append(last, A->data);
        A = A->next;
    }

    last->next = NULL;
    last = C;
    C = C->next;
    free(last);
    return C;
}


void ListPrint(LinkList A) {
    printf("中元素有%3d个:", ListLength(A));

    ListNode *p;

    p = A->next;

    while (p != NULL) {
        printf("%4d", p->data);
        p = p->next;
    }
    printf("\n");
}
