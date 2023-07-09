
#include<iostream>

using namespace std;

class Node {

    public:
    
    int data;
    Node* left, *right;

    Node(int val) {

        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insertBST(Node* root, int val) {

    if(root==NULL) {
        return new Node(val);
    }

    if(root->data<val) {
        root->right = insertBST(root->right, val);
    }
    else {
        root->left = insertBST(root->left, val);
    }

    return root;
}

Node* searchBst(Node* root, int data) {

    if(root==NULL)
    return NULL;

    if(root->data==data)
    return root;

    Node* node = NULL;
    Node* lnode = NULL;

    if(root->data<data)
    node = searchBst(root->right, data);

    if(root->data>data)
    lnode = searchBst(root->left, data);

    if(node!=NULL)
    return node;

    return lnode;
}

Node* inorderSuccessor(Node* root) {

    if(root==NULL)
    return NULL;

    Node* curr = root;

    while(curr && curr->left!=NULL)
    curr = curr->left;

    return curr;
}

Node* deleteBST(Node* root, int data) {

    if(root==NULL)
    return NULL;

    if(root->data>data)
    root->left = deleteBST(root->left, data);

    if(root->data<data)
    root->right = deleteBST(root->right, data);

    if(root->data==data) {

        if(root->left==NULL) {

            Node* temp = root->right;
            delete(root);
            return temp;
        }
        else if(root->right==NULL) {

            Node* temp = root->left;
            delete(root);
            return temp;
        }
        else {
            Node* inorderSucc = inorderSuccessor(root->right);
            root->data = inorderSucc->data;
            root->right = deleteBST(root->right, inorderSucc->data);
        }
    }

    return root;
}

Node* createBst(int preorder[], int *index, int key, int min, int max, int n) {

    if(*index>=n)
    return NULL;

    Node* root = NULL;

    if(key > min && key < max) {

        root = new Node(key);
        *index = *index+1;
        
        if(*index<n)
        root->left = createBst(preorder, index, preorder[*index], min, key, n);

        if(*index<n)
        root->right = createBst(preorder, index, preorder[*index], key, max, n);
    }

    return root;
}

bool checkForBST(Node* root, int min, int max) {

    if(root==NULL)
    return true;


    if(checkForBST(root->left, min, root->data) && checkForBST(root->right, root->data, max)) {

        if(root->data > min && root->data < max)
        return true;
        return false;
    }

    return false;
}

Node* createBSTfromSortedArray(int arr[], int start, int end) {

    if(start>end)
    return NULL;

    int mid = (start+end)/2;

    Node* root = new Node(arr[mid]);

    root->left = createBSTfromSortedArray(arr, start, mid-1);
    root->right = createBSTfromSortedArray(arr, mid+1, end);

    return root;
}

void inorder(Node* root) {

    if(root==NULL)
    return;

    inorder(root->left);
    cout<< root->data <<" ";
    inorder(root->right);
}

int main() {

    system("clear");

    int preorder[] = {10, 20, 30, 40, 50};

    int index = 0;
    
   Node* root = createBSTfromSortedArray(preorder, 0, 4);

    if(checkForBST(root, INT_MIN, INT_MAX)) {

        cout<<"\nThe given tree is BST!";
    }
    else {

        cout<<"\nThe given tree is not a BST!";
    }

    cout<<endl;

    inorder(root);

    return 0;
}