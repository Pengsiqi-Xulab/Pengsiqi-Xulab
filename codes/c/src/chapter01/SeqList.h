//定义线性列表
typedef struct {
    DataType list[ListSize];
    int length;
}SeqList;


void InitList(SeqList *L) {
    L->length = 0;
}


int isListEmpty(SeqList L) {
    if (L.length == 0)
        return 1;
    else
        return 0;
}


int GetElem(SeqList L, int i, DataType *e) {
    if (i < 1 || i > L.length)
        return -1;
    *e = L.list[i-1];
    return 1;
}


int LocateElem(SeqList L, DataType e) {
    int i;
    for (i = 0; i < L.length; i++)
        if (L.list[i] == e)
            return i+1;
    return 0;
}


int InsertList(SeqList *L, int i, DataType e) {
    int j;
    if (i < 1 || i > L->length + 1) {
        printf("插入位置不合法。\n");
        return -1;
    } else if (L->length >= ListSize) {
        printf("顺序表已满，不能再插入元素。\n");
        return 0;
    } else {
        for (j = L->length; j >= i; j--)
            L->list[j] = L->list[j-1];
        L->list[i-1] = e;
        L->length +=  1;
        return 1;
    }
}


int DeletList(SeqList *L, int i) {
    int j;
    if (L->length <= 0) {
        printf("顺序表已空，无法删除。\n");
        return 0;
    } else if (i < 1 || i >= L->length) {
        printf("删除的位置不合法。\n");
        return -1;
    } else {
        for (j = i; j <= L->length; j++)
            L->list[j-1] = L->list[j];
        L->length -= 1;
        return 1;
    }
}


int ListLength(SeqList L) {
    return L.length;
}


void ClearList(SeqList *L) {
    L->length = 0;
}




