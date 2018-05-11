/** @file queue.c
 *
 * Definitions for linked queue operations.
 */

# include "header.h"
# include "queue.h"

struct linked_queue_node;
typedef struct linked_queue_node   q_node;
typedef struct linked_queue_node  *pq_node;

struct linked_queue_node{
    value_type     *pdata;
    pq_node         next;
};

struct linked_queue {
    pq_node    front;
    pq_node    rear;
    size_type  size;
};

pqueue
create_queue(void) {
    pqueue    pq;

    if ((pq = (pqueue) malloc(sizeof(queue))) == NULL)
        null_return("create_queue() error.");

    pq->front = pq->rear = NULL;
    pq->size = 0;

    return pq;
}

static pq_node
create_queue_node(value_type *pv) {
    pq_node    pn;

    if ((pn = (pq_node) malloc(sizeof(q_node))) == NULL)
        null_return("create_queue_node() error.");
    
    pn->pdata = pv;
    pn->next = NULL;

    return pn;
}

int
is_empty_queue(pqueue pq) {
    return pq->size == 0;
}

void
enqueue(pqueue pq, value_type *pd) {
    pq_node pn;

    if (pq == NULL || pd == NULL)
        return;

    pn = create_queue_node(pd);

    if (is_empty_queue(pq)) {
        pq->rear = pq->front = pn;
    } else {
        pq->rear->next = pn;
        pq->rear = pn;
    }
    pq->size++;
}

value_type *
dequeue(pqueue pq) {
    pq_node pn;
    value_type *pd;
    if (pq == NULL || is_empty_queue(pq))
        return NULL;

    pn = pq->front;
    pd = pn->pdata;
    pq->front = pq->front->next;
    pq->size--;
    free(pn);

    return pd;
}

void
clear_queue(pqueue pq) {
    while (dequeue(pq) != NULL);
}

void
free_queue(pqueue pq) {
    clear_queue(pq);
    free(pq);
}

size_type
queue_size(pqueue pq) {
    return pq->size;
}
