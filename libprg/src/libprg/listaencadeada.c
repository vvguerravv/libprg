#include <libprg/libprg.h>

void addList(ChainedList_t *queue, no_t **node, int value)
{
    no_t *new = (no_t*) malloc(sizeof(no_t));
    new->element = value;
    new->next = NULL;

    if (*node == NULL) {
        *node = new;
        queue->start = *node;
        queue->size++;
    } else {
        no_t *current = *node;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
        queue->size++;
    }
}

int removeList(ChainedList_t *queue, no_t **node)
{
    if(*node == NULL){
        return 0;
    }

    no_t *current = *node;
    *node = (*node)->next;
    free(current);
    queue->size--;
    return 1;
}

int searchList(no_t **node, int element)
{
    int i = 0;
    while(*node != NULL){
        if((*node)->element == element){
            return i;
        }
        *node = (*node)->next;
        i++;
    }
    return -1;
}

void addStack(Stackist_t *stack, no_t **node, int element) {
    no_t *new = (no_t*) malloc(sizeof(no_t));
    if (new == NULL) {
        return;
    }

    new->element = element;
    new->next = *node;
    *node = new;
    stack->high = new;
    stack->size++;
}

int removeStack(Stackist_t *stack, no_t **node)
{
    if (*node == NULL) {
        return 0;
    }

    no_t *current = stack->high;
    *node = stack->high->next;
    free(current);
    stack->high = *node;

    return 1;
}

int searchStack(no_t **node, int element)
{
    int i = 0;
    while(*node != NULL){
        if((*node)->element == element){
            return i;
        }
        *node = (*node)->next;
        i++;
    }
    return -1;
}

void printNo(no_t *node)
{
    while(node != NULL){
        printf("%d ", node->element);
        node = node->next;
    }
}

void addCircle(no_t **node,bool op, int value)
{
    no_t *new = (no_t *) malloc(sizeof(no_t));
    new->element = value;
    new->next = *node;

    if(*node == NULL){
        *node = new;
        return;
    }

    if(!op){
            no_t *current = *node;
            while(current->next != *node){
                current = current->next;
            }
            current->next = new;

    } else{
       no_t  *current = *node;
        while (current->next != *node && current->element > value){
            current = current->next;
        }
        new->next = current->next;
        current->next = new;
    }
}

int removeCircle(no_t **node, int value)
{
    if(*node == NULL){
        return -1;
    }
    no_t *current = *node;
    while(current != NULL){
        if(current->next->element == value){
            current->next = current->next->next;
            return 1;
        }
        current = current->next;
    }
    return 0;
}

