
#include<iostream>
#include<climits>

using namespace std;

struct Node {

    int data;
    Node* left, *right;

    Node(int val) {

        data = val;
        left = NULL;
        right = NULL;
    }
};

struct Info {

    int min;
    int max;
    int size;
    int ans;
    bool isBST;
};

Info largestBstInBt(Node* root) {

    if(root==NULL) {

        return {INT_MAX, INT_MIN, 0, 0, true};
    }

    if(root->left==NULL && root->right==NULL) {

        return {root->data, root->data, 1, 1, true};
    }

    Info left = largestBstInBt(root->left);
    Info right = largestBstInBt(root->right);

    Info curr;

    curr.size = left.size + right.size + 1;

    if(left.isBST && right.isBST && left.max < root->data && right.min > root->data) {

        curr.min = min(left.min, min(right.min, root->data));
        curr.max = max(left.max, max(right.max, root->data));
        curr.ans = curr.size;
        curr.isBST = true;

        return curr;
    }

    curr.min = min(left.min, min(right.min, root->data));
    curr.max = max(left.max, max(right.max, root->data));
    curr.ans = max(left.ans, right.ans);
    curr.isBST = false;

    return curr;
}

void calcPointers(Node* root, Node** first, Node** mid, Node** last, Node** prev) {

    if(root==NULL)
        return;

    calcPointers(root->left, first, mid, last, prev);

    if(*prev && (root->data < (*prev)->data)) {

        if(!*first) {

            *first = *prev;
            *mid = root;
        }
        else {

            *last = root;
        }
    }

    *prev = root;

    calcPointers(root->right, first, mid, last, prev);
}

void swap(int* num1, int* num2) {

    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void restoreBST(Node* root) {

    if(root==NULL)
        return;

    
    Node* first, *mid, *last, *prev;
    first = NULL;
    mid = NULL;
    last = NULL;
    prev = NULL;

    calcPointers(root, &first, &mid, &last, &prev);

    if(first && last) {

        swap(&(first->data), &(last->data));
        return;
    }
    else {

        swap(&(first->data), &(mid->data));
    }
    
}

void inorder(Node* root) {

    if(root==NULL)
        return;

    inorder(root->left);

    cout<<root->data<<" ";

    inorder(root->right);
}

int main() {

   system("clear");
    
   Node* root = new Node(6);

   root->left = new Node(9);
   root->right = new Node(3);
   root->left->left = new Node(1);
   root->left->right = new Node(4);
   root->right->right = new Node(13);

   inorder(root);

   restoreBST(root);

   cout<<endl;

   inorder(root);

    return 0;
}