#include <libprg/libprg.h>

tree_t *crateTree(int value)
{
    tree_t *node = (tree_t *) malloc(sizeof(tree_t));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void destruct_tree(tree_t *node)
{
    if(node != NULL){
        destruct_tree(node->left);
        destruct_tree(node->right);
        free(node);
    }
}

tree_t *insert_value(tree_t  *root, int value)
{
    if(root == NULL){
        return (crateTree(value));
    } else if(value < root->value){
        root->left = insert_value(root->left,value);
    } else if(value > root->value){
        root->right = insert_value(root->right,value);
    }
    return root;
}

bool searchTree(tree_t *root, int value)
{
    if(root == NULL){
        return false;
    }

    if(value == root->value){
        return true;
    }

    if (value < root->value){
        return searchTree(root->left, value);
    }

    return searchTree(root->right,value);
}

int maxNum(tree_t *root)
{
    if(root != NULL){
        if(root->right != NULL){
            return maxNum(root->right);
        } else {
            return root->value;
        }
    }
    return -1;
}

int minNum(tree_t *root)
{
    if(root != NULL){
        if(root->left != NULL){
            return minNum(root->left);
        } else{
            return root->value;
        }
    }
}

tree_t *son(tree_t *root,int value,int *level)
{
    if(root == NULL){
        return root;
    }
    if(value == root->value){
        return root;
    }

    if (value < root->value){
        (*level)++;
        return son(root->left, value,level);
    } else{
        (*level)++;
        return son(root->right,value,level);
    }

}

tree_t *removeNum(tree_t *root, int value)
{
    if (root == NULL)
        return root;

    if (value < root->value )
        root->left = removeNum(root->left, value);
    else if (value > root->value)
        root->right = removeNum(root->right, value);
    else {
        if (root->left == NULL) {
            tree_t *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            tree_t *temp = root->left;
            free(root);
            return temp;
        }

        tree_t *temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;

        root->value = temp->value;

        root->right = removeNum(root->right, temp->value);
    }
    return root;
}

void inOrder(tree_t *root)
{
    if(root != NULL){
        inOrder(root->left);
        printf("%d ",root->value);
        inOrder(root->right);
    }
}

void preOder(tree_t *root)
{
    if(root != NULL){
        printf("%d ",root->value);
        preOder(root->left);
        preOder(root->right);
    }
}

void posOrder(tree_t *root)
{
    if(root != NULL){
        posOrder(root->left);
        posOrder(root->right);
        printf("%d ",root->value);
    }
}

void width(tree_t *root,int size)
{
    queue_t *queue;

    if((queue = malloc(sizeof(tree_t))) == NULL){
        exit(EXIT_FAILURE);
    }
    if((queue->array = calloc(size,sizeof(queue_t))) == NULL){
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < size; i++){
        queue->array[i] == NULL;
    }

    queue->inicio = 0;
    queue->fim = 0;
    queue->total = 0;
    queue->size = size;

    while(root != NULL){
        printf("%d ",root->value);
        if(root->left != NULL){
            enqueueTree(root->left,queue);
        } if(root->right != NULL){
            enqueueTree(root->right,queue);
        }
        root = dequeueTree(root,queue);
    }
}

void enqueueTree(tree_t *root, queue_t *queue)
{
    if(queue->size == queue->total){
        return;
    }
    queue->array[queue->fim] = root;
    queue->fim = (queue->fim + 1) % queue->size;
    queue->total++;
}

tree_t *dequeueTree(tree_t *root, queue_t *queue)
{
    if(queue->total == 0){
        return NULL;
    }
    queue->inicio = (queue->inicio + 1) % queue->size;
    queue->total--;
    return queue->array[queue->inicio];
}

void printTree(tree_t *root)
{
    if(root != NULL){
        if(root->left != NULL){
            printf("%d -- %d\n",root->value,root->left->value);
        } if(root->right != NULL){
            printf("%d -- %d\n",root->value,root->right->value);
        }
        printTree(root->left);
        printTree(root->right);
    }

}

void printGraph(tree_t *root)
{
    printf("strict graph{\n"
           "label=\"Árvore de busca binária\";\n"
           "node [shape=\"circle\", color=\"#339966\", style=\"filled\",\n"
           "fixedsize=true];\n");
    printTree(root);
    printf("}\n");
}
