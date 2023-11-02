#include <libprg/libprg.h>

void addList(ChainedList_t *queue, no_t **no, int value)
{
    no_t *new = (no_t*) malloc(sizeof(no_t));
    new->element = value;
    new->next = NULL;

    if (*no == NULL) {
        *no = new;
        queue->start = *no;
        queue->size++;
    } else {
        no_t *current = *no;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
        queue->size++;
    }
}

int removeList(ChainedList_t *queue, no_t **no)
{
    if(*no == NULL){
        return 0;
    }

    no_t *current = *no;
    *no = (*no)->next;
    free(current);
    queue->size--;
    return 1;
}

int searchList(no_t **no, int element)
{
    int i = 0;
    while(*no != NULL){
        if((*no)->element == element){
            return i;
        }
        *no = (*no)->next;
        i++;
    }
    return -1;
}

void addStack(Stackist_t *stack, no_t **no, int element) {
    no_t *new = (no_t*) malloc(sizeof(no_t));
    if (new == NULL) {
        return;
    }

    new->element = element;
    new->next = *no;
    *no = new;
    stack->high = new;
    stack->size++;
}

int removeStack(Stackist_t *stack, no_t **no)
{
    if (*no == NULL) {
        return 0;
    }

    no_t *current = stack->high;
    *no = stack->high->next;
    free(current);
    stack->high = *no;

    return 1;
}

int searchStack(no_t **no, int element)
{
    int i = 0;
    while(*no != NULL){
        if((*no)->element == element){
            return i;
        }
        *no = (*no)->next;
        i++;
    }
    return -1;
}

void printNo(no_t *no)
{
    while(no != NULL){
        printf("%d ",no->element);
        no = no->next;
    }
}

