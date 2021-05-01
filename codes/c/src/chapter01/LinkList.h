typedef struct Node
{
    DataType data;
    struct  Node *next;
}ListNode, *LinkList;


void InitList(LinkList *head) {
    if ((*head = (LinkList)malloc(sizeof(ListNode))) == NULL)
        exit(-1);
    (*head)->next = NULL;
}


int isListEmpyt(LinkList head) {
    if (head->next == NULL)
        return 1;
    else
        return 0;
}


ListNode *Get(LinkList head, int i) {
    ListNode *p;
    int j;

    if (isListEmpyt(head))
        return NULL;

    if (i < 1)
        return NULL;

    j = 0;
    p = head;

    while (p->next != NULL && j < i) {
        p = p->next;
        j++;
    }

    if (j == i)
        return p;
    else
        return NULL;
}


ListNode *LocateElem(LinkList head, DataType e) {
    ListNode *p;
    p = head->next;

    while (p) {
        if (p->data != e)
            p = p->next;
        else
            break;
    }
    return p;
}


int LocatePos(LinkList head, DataType e) {
    ListNode *p;
    int i;

    if (isListEmpyt(head))
        return 0;

    p = head->next;
    i = 1;

    while (p) {
        if (p->data == e)
            return i;
        else {
            p = p->next;
            i++;
        }
    }
    // if (!p)
        return 0;
}


int InsertList(LinkList head, int i, DataType e) {
    ListNode *pre, *p;
    int j;
    pre = head;
    j = 0;

    while (pre->next != NULL && j < i-1) {
        pre = pre->next;
        j++;
    }

    if (j != i-1) {
        printf("插入位置错误！\n");
        return 0;
    }

    if ((p=(ListNode*)malloc(sizeof(ListNode))) == NULL)
        exit(-1);

    p->data = e;
    p->next = pre->next;
    pre->next = p;
    return 1;
}


int DeleteList(LinkList head, int i) {
    ListNode *pre, *p;
    int j;
    pre = head;
    j = 0;

    while (pre->next != NULL && pre->next->next != NULL && j < i-1) {
        pre = pre->next;
        j++;
    }

    if (j != i-1) {
        printf("删除位置有误。\n");
        return 0;
    }

    p = pre->next;
    // *e = p->data;
    pre->next = p->next;
    free(p);
    return 1;
}


int ListLength(LinkList head) {
    ListNode *p;
    int count = 0;
    p = head;

    while (p->next != NULL) {
        p = p->next;
        count++;
    }
    return count;
}


void DestroyList(LinkList head) {
    ListNode *p, *q;
    p = head;

    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }
}
