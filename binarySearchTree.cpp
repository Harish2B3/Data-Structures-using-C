#include<stdio.h>
#include<stdlib.h>

struct BST{
    int key;
    struct BST *left, *right;
};

typedef struct BST bst;

bst *newnodeCreate(int value){
    bst *temp = (bst*)malloc(sizeof(bst));
    temp->key = value;
    temp->left = temp->right = NULL;
    return temp;
}

bst *searchNode(bst *root, int target){
    if(root == NULL || root->key == target){
        return root;
    }
    if(root->key<target){
        return searchNode(root->right,target);
    }
    return searchNode(root->left,target);
}

bst *insertNode(bst *node, int value){
    if(node==NULL){
        return newnodeCreate(value);
    }
    if(value<node->key){
        node->left = insertNode(node->left,value);
    }
    else if(value>node->key){
        node->right = insertNode(node->right,value);
    }
    return node;
}

void postOrder(bst *root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d",root->key);
    }
}

void inOrder(bst *root){
    if(root!=NULL)
    {
        inOrder(root->left);
        printf("%d",root->key);
        inOrder(root->right);
    }
}

void preOrder(bst *root){
    if(root != NULL){
        printf("%d",root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

bst *findMin(bst *root){
    if(root == NULL){
        return NULL;
    }else if(root->left != NULL){
        return findMin(root->left);
    }
    return root;
}

bst *deletenode(bst *root, int x){
    if(root == NULL){
        return NULL;
    }
    if(x>root->key){
        root->right = deletenode(root->right, x);
    }
    else if(x<root->key){
        root->left = deletenode(root->left,x);
    }else if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
    else if(root->left == NULL || root->right==NULL){
        bst *temp;
        if(root->left == NULL){
            temp = root->right;
        }else{
            temp = root->left;
        }

        free(root);
        return temp;
    }else{
        bst *temp = findMin(root->right);
        root->key = temp->key;
        root->right = deletenode(root->right,temp->key);
    }
    return root;
}

int main(){
    bst *root = NULL;
    root = insertNode(root,50);
    insertNode(root,30);
    insertNode(root,20);
    insertNode(root,40);
    insertNode(root,40);
    insertNode(root,60);
    insertNode(root,80);
    insertNode(root,80);
    insertNode(root,70);
    if(searchNode(root,60) != NULL){
        printf("60 found");
    }else{
        printf("60 not found");
        printf("Post Order \n");
        postOrder(root);
        printf("Pre Order\n");
        preOrder(root);
        printf("InOrder\n");
        inOrder(root);

        bst *temp = deletenode(root,70);
        printf("After delete = \n");
        inOrder(root);
        return 0;
    }
}
