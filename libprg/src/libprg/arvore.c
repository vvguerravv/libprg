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

tree_t *teste(tree_t *root,int value,int *level)
{
    if(root == NULL){
        return root;
    }
    if(value == root->value){
        return root;
    }

    if (value < root->value){
        (*level)++;
        return teste(root->left, value,level);
    } else{
        (*level)++;
        return teste(root->right,value,level);
    }

}