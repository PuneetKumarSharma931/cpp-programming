
#include<iostream>
#include<vector>
#include<stack>
#include<limits>

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

vector<Node*> constructTrees(int start, int end) {

    vector<Node*> trees;

    if(start>end) {

        trees.push_back(NULL);
        return trees;
    }

    for(int i=start;i<=end;i++) {

        vector<Node*> leftSubtrees = constructTrees(start, i-1);
        vector<Node*> rightSubtrees = constructTrees(i+1, end);

        for(int j=0;j<leftSubtrees.size();j++) {

            Node* left = leftSubtrees[j];

            for(int k=0;k<rightSubtrees.size();k++) {

                Node* right = rightSubtrees[k];

                Node* node = new Node(i);

                node->left = left;
                node->right = right;

                trees.push_back(node);
            }
        }
    }

    return trees;
}

void zigZagTraversal(Node* root) {

    if(root==NULL)
    return;

    stack<Node*> currLevel;
    stack<Node*> nextLevel;
    Node* node = root;
    bool LeftToRight = true;

    currLevel.push(node);

    while(!currLevel.empty() || !nextLevel.empty()) {

            if(LeftToRight) {

                if(currLevel.empty()) {

                    LeftToRight = false;
                    currLevel.swap(nextLevel);
                }
                else {

                    node = currLevel.top();
                    currLevel.pop();

                    cout<<node->data<<" ";

                    if(node->left)
                    nextLevel.push(node->left);

                    if(node->right)
                    nextLevel.push(node->right);
                }

            }

            if(!LeftToRight) {

                if(currLevel.empty()) {

                    LeftToRight = true;
                    currLevel.swap(nextLevel);
                }
                else {

                    node = currLevel.top();
                    currLevel.pop();

                    cout<<node->data<<" ";

                    if(node->right)
                    nextLevel.push(node->right);

                    if(node->left)
                    nextLevel.push(node->left);
                }
            }
        }
}

bool identicalBST(Node* root1, Node* root2) {

    if(root1==NULL && root2==NULL) {
        return true;
    }
    else if(root1==NULL || root2==NULL) {

        return false;
    }
    else {

    if(identicalBST(root1->left, root2->left) && identicalBST(root1->right, root2->right)) {

        if(root1 && root2) {

            if(root1->data==root2->data) {

                return true;
            }
            else {
                return false;
            }
        }
        else {

            return false;
        }
    }
    else {

        return false;
    }
    }
}

void maxBSTinBT(Node* root, int *length, int *maxLength) {

    if(root==NULL) {

        return;
    }

    maxBSTinBT(root->left, length, maxLength);
    maxBSTinBT(root->right, length, maxLength);

    if(root->left && root->right) {

        if((root->left->data < root->data) && (root->right->data > root->data)) {

            *length+=1;
            return;
        }
        else{

            *maxLength = max(*maxLength, *length);
            *length = 0;
        }
    }
    else if(root->left && !root->right) {

        if(root->left->data < root->data) {

            *length+=1;
            return;
        }
        else {

            *maxLength = max(*maxLength, *length);
            *length = 0;
        }
    }
    else if(!root->left && root->right) {

        if(root->right->data > root->data) {

            *length+=1;
            return;
        }
        else {

            *maxLength = max(*maxLength, *length);
            *length = 0;
        }
    }
    else {

        *length+=1;
        return;
    }
}

void preorder(Node* root) {

    if(root==NULL) {

        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main() {

    system("clear");
    
    int maxLength = -1000;
    int length = 0;

    int *pMaxLength = &maxLength;
    int *pLength = &length;

    Node* root = new Node(5);

    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right = new Node(6);

    maxBSTinBT(root, pLength, pMaxLength);

    cout<<"The Max Length of BST is: "<<maxLength;

    return 0;
}