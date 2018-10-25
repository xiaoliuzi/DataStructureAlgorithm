#include <stdio.h>
#include <stdlib.h>
// the size of the sequence list
#define N 10
#define OK
#define ERROR -1

typedef struct{
    // base address of the array
    int *elem;
    // current length of the array
    int length;
    // current capacity of the array
    int listsize;
}SqList;


// global error tag
int error = 0;// Reserverd. To replace ERROR 

int Init(SqList *L) {
    L->elem = (int*)malloc(N*sizeof(int));
    if(L->elem == NULL) return ERROR;
    L->length = 0;
    L->listsize = N;
    return OK;
}

// Insert an element to it-h index.(The index is begin from 0.)
// ordinary array: 1 2 3 4 After SqListInsert(L, 2, 55); It becomes 1 2 55 3 4
int SqListInsert(SqList *L, int i, int e) {
    if(L==NULL || i<0) return ERROR;
    if(i > L->listsize) return ERROR;
    if(i >= L->length) {
        L->elem[i] = e;
        L->length++;
    }
    int n = L->length-1;
    for(;n>=i; --n)
        L->elem[n+1] = L->elem[n];
    L->elem[i] = e;
    L->length++;
    return OK;
}

void PrintSqList(const SqList M) {
    int *p = NULL;
    for(p=M.elem; p<=(M.elem+M.length-1); p++) 
        printf("%d ", *p);
    printf("\n");
}

int main(void)
{
    int i, n=5, e;
    SqList *L, M;
    L=&M;
    Init(L);
    printf("Please input five numbers:\n");
    for(i=0; i<n; ++i) {
        scanf("%d", &e);
        SqListInsert(L, i, e);
    }
    PrintSqList(M);
    SqListInsert(L, 3, 999);
    printf("After insert:\n");
    PrintSqList(M);
    return 0;
}
