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

tree_t  *inOrder(tree_t *root)
{
    if(root != NULL){
        inOrder(root->left);
        printf("%d ",root->value);
        inOrder(root->right);
    }
}

tree_t *preOder(tree_t *root)
{
    if(root != NULL){
        printf("%d ",root->value);
        preOder(root->left);
        preOder(root->right);
    }
}

tree_t *posOrder(tree_t *root)
{
    if(root != NULL){
        posOrder(root->left);
        posOrder(root->right);
        printf("%d ",root->value);
    }
}

tree_t *width(tree_t *root,fila_t *fila)
{
    while(root != NULL){
        printf("%d ",root->value);
        if(root->left != NULL){
            enqueue(fila,root)
        }
    }
}



tree_t *enqueueTree(tree_t *root);
{
    if(fila->tamanho == fila->total){
        return 1;
    }
    fila->vetor[fila->fim] = elemento;
    fila->fim = (fila->fim + 1)% fila ->tamanho;
    fila->total++;

    return 0;
}