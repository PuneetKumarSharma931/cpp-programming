
#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* create(int data) {

    struct Node *nw = (struct Node*)malloc(sizeof(struct Node));

    nw->data = data;
    nw->left = NULL;
    nw->right = NULL;

    return nw;
}

void preorder(struct Node* root) {

    if(root!=NULL) {

        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {

    if(root!=NULL) {

        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void inorder(struct Node* root) {

    if(root!=NULL) {

        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

int isBST(struct Node* root) {

    static struct Node *prev = NULL;

    if(root!=NULL) {

        if(!isBST(root->left)){
            return 0;
        }

        if(prev!=NULL && root->data <= prev->data) {
            return 0;
        }

        prev = root;

        return isBST(root->right);
    }
    else {
        return 1;
    }
}

int main() {

    system("clear");

    struct Node *root,*p1,*p2,*p3,*p4;

    root = create(5);
    p1 = create(3);
    p2 = create(6);
    p3 = create(1);
    p4 = create(4);

    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;

    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    inorder(root);
    printf("\n");

    printf("%d",isBST(root));


    return 0;
}