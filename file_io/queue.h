/** @file queue.h
 *
 * Declarations for queue operations.
 */

# ifndef QUEUE_H
# define QUEUE_H

# include "header.h"

struct linked_queue;
typedef struct linked_queue  queue;
typedef struct linked_queue *pqueue;

pqueue create_queue(void);
int is_empty_queue(pqueue);
void enqueue(pqueue, value_type *);
value_type * dequeue(pqueue);
void clear_queue(pqueue);
void free_queue(pqueue);
size_type queue_size(pqueue);

# endif
