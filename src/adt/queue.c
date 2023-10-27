#include <stdio.h>
#include "queue.h"
void CreateQueue(Queue *q) {
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(Queue q) {
    return (IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF);
}

boolean isFull(Queue q) {
    if (IDX_HEAD(q) == 0) {
        return (IDX_TAIL(q) == CAPACITY - 1);
    }
    else {
        return (IDX_HEAD(q) == IDX_TAIL(q) + 1);
    }
}

int length(Queue q) {
    if(isEmpty(q)){
        return 0;
    }
    else{
        if (IDX_HEAD(q) < IDX_TAIL(q)) {
            return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
        }
        else {
            return (CAPACITY + IDX_TAIL(q) - IDX_HEAD(q) + 1);
        }
    }
}

void enqueue(Queue *q, ElType val) {
    if(isEmpty(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        TAIL(*q) = val;
    }
    else if (!isFull(*q)){
        if (IDX_TAIL(*q) == CAPACITY-1) {
            IDX_TAIL(*q) = 0;
        }
        else {
            IDX_TAIL(*q)++;
        }
        TAIL(*q) = val;
    }
}

void dequeue(Queue *q, ElType *val) {
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q)){
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else {
        if (IDX_HEAD(*q) == CAPACITY - 1) {
            IDX_HEAD(*q) = 0;
        }
        else {
            IDX_HEAD(*q)++;
        }
    }
}

void displayQueue(Queue q) {
    if(isEmpty(q)){
        printf("[]\n");
    }
    else{
        int n = length(q);
        int temp;
        dequeue(&q, &temp);
        printf("[");
        while (n > 1) {
            printf("%d,", temp);
            dequeue(&q, &temp);
            n--;
        }        
        printf("%d]\n", temp);
    }
}
