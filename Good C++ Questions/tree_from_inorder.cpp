
#include<iostream>
#include<vector>
#include<queue>
#include<math.h>

using namespace std;

class Node {

    public:

    int data;
    Node* left;
    Node* right;

    Node(int val) {

        data = val;
        left = NULL;
        right = NULL;
    }
};

int search(int inorder[], int start, int end, int curr) {

    for(int i=start;i<=end;i++) {

        if(inorder[i]==curr)
        return i;
    }
    return -1;
}

Node* build_Tree(int inorder[], int preorder[], int start, int end) {

    if(start>end) {

        return NULL;
    }

    static int index = 0;

    int curr = preorder[index];
    index++;

    Node* node = new Node(curr);

    if(start==end) {

        return node;
    }

    int pos = search(inorder, start, end, curr);

    node->left = build_Tree(inorder, preorder, start, pos-1);
    node->right = build_Tree(inorder, preorder, pos+1, end);

    return node;
}

Node* build_Tress_post(int postorder[], int inorder[], int start, int end) {

    if(start>end) {
        return NULL;
    }
    
    static int index = 5;

    int curr = postorder[index];
    index--;

    Node* node = new Node(curr);

    if(start==end) {

        return node;
    }

    int pos = search(inorder, start, end, curr);

    node->right = build_Tress_post(postorder, inorder, pos+1, end);
    node->left = build_Tress_post(postorder, inorder, start, pos-1);

    return node;
}

void levelTraversal(Node* root) {

    queue<Node*> que;
    Node* node;

    if(root==NULL) {

        return;
    }

    que.push(root);

    while(!que.empty()) {

        node = que.front();
        que.pop();
        cout<<node->data<<" ";
        
        if(node->left!=NULL) {
            que.push(node->left);
        }

        if(node->right!=NULL) {

            que.push(node->right);
        }
    }
}

void sumAtkthLevel(Node* root, int k) {

    queue<Node*> que;
    int sum = 0;
    int count = 0;
    Node* node;

    if(root==NULL) {
        return;
    }

    que.push(root);
    que.push(NULL);

    while(!que.empty()) {

        if(que.front()==NULL) {
            
            if(count==k) {
            cout<<sum<<" ";
            return;
            }

            count++;
            que.pop();
            que.push(NULL);
        }

        if(que.front()==NULL) {
            return;
        }

        node = que.front();
        que.pop();

        if(count==k)
        sum+=node->data;

        if(node->left!=NULL)
        que.push(node->left);

        if(node->right!=NULL)
        que.push(node->right);

    }

}

int countNodes(Node* root) {

    if(root==NULL) {

        return 0;
    }

    return countNodes(root->left) + countNodes(root->right) + 1;

}

int sumOfBinaryTree(Node* root) {


    if(root==NULL) {
        return 0;
    }

    return sumOfBinaryTree(root->left) + sumOfBinaryTree(root->right) + root->data;
}

int heightOfTree(Node* root) {

    if(root==NULL) {

        return 0;
    }
    else if(root->left!=NULL || root->right!=NULL) {
        
        return (max(heightOfTree(root->left), heightOfTree(root->right)) + 1);
    }
    else {

        return 0;
    }

}

int diameterOfTree(Node* root) {

    if(root==NULL) {
        return 0;
    }


    int leftHeight = heightOfTree(root->left)+1;
    int rightHeight = heightOfTree(root->right)+1;

    int currentDiameter = leftHeight + rightHeight +1;

    int leftDiameter = diameterOfTree(root->left);
    int rightDiameter = diameterOfTree(root->right);

    return max(currentDiameter, max(leftDiameter, rightDiameter));
}

int diameterOfTreeOptimized(Node* root, int* height) {

    if(root==NULL) {

        *height = 0;
        return 0;
    }

    int lh=0, rh = 0;

    int lD = diameterOfTreeOptimized(root->left, &lh);
    int rD = diameterOfTreeOptimized(root->right, &rh);

    int currD = lh + rh +1;
    *height = max(lh, rh) + 1;

    return max(currD, max(lD,rD));
}

void replaceSum(Node* root) {

    if(root==NULL) {
        return;
    }

    root->data = sumOfBinaryTree(root);

    replaceSum(root->left);
    replaceSum(root->right);
}

bool isBalanced(Node* root) {

    if(root==NULL) {
        return true;
    }
    if(root->left==NULL && root->right==NULL) {
        return true;
    }

    if(isBalanced(root->left) && isBalanced(root->right)) {

        int lh = heightOfTree(root->left);
        int rh = heightOfTree(root->right);

        if((abs(lh-rh))<=1) {
            return true;
        }
        else {
            false;
        }

    }
    else {

        return false;
    }  
}

bool optimizedIsBalance(Node* root, int *height) {

    if(root==NULL) {
        
        *height = 0;
        return true;
    }

    int lh = 0;
    int rh = 0;

    if(optimizedIsBalance(root->left , &lh) && optimizedIsBalance(root->right, &rh)) {

        if(root->left!=NULL || root->right!=NULL) {
            *height = max(lh, rh) + 1;
        }

        if(abs(lh-rh)<=1) {
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

void rightView(Node* root) {

    if(root==NULL) {
        return;
    }

    queue<Node*> que;
    que.push(root);
    que.push(NULL);
    Node* node;

    while(!que.empty()) {

        if(que.front()==NULL) {

            cout<<node->data<<" ";
            que.pop();
            que.push(NULL);
        }

        if(que.front()==NULL)  {
            return;
        }

        node = que.front();
        que.pop();

        if(node && node->left)
        que.push(node->left);

        if(node && node->right)
        que.push(node->right);

    }
}

void leftView(Node* root) {

    if(root==NULL) {
        return;
    }

    queue<Node*> que;
    Node* node;

    que.push(root);
    que.push(NULL);
    cout<<root->data<<" ";

    while(!que.empty()) {

       if(que.front()==NULL) {
           que.pop();
           que.push(NULL);
           
           if(que.front()) {
               cout<<que.front()->data<<" ";
           }
           else {
               return;
           }
       }

       node = que.front();
       que.pop();

       if(node && node->left)
       que.push(node->left);

       if(node && node->right)
       que.push(node->right);

    }
}

bool getPath(Node* root, int key, vector<int> &path) {

    if(root==NULL) {
        return false;
    }

    path.push_back(root->data);

    if(getPath(root->left, key, path) || getPath(root->right, key, path)) {

        return true;
    }

    if(root->data==key) {
        return true;
    }
    else {
        
        path.pop_back();
        return false;
    }
}

int LCA(Node* root, int n1, int n2) {

    vector<int> path1, path2;

    if(getPath(root, n1, path1) && getPath(root, n2, path2)) {

        int CA = 0;

       for(CA=0;CA<=path1.size()&&path2.size();CA++) {
           if(path1[CA]!=path2[CA]) {
               break;
           }
       } 

       return path1[CA-1];
    }

    return -1;
}

Node* LCAOptimized(Node* root, int n1, int n2) {

    if(root==NULL) {
        return NULL;
    }

    if(root->data==n1 || root->data==n2) {
        return root;
    }

    Node* leftLCA = LCAOptimized(root->left, n1, n2);
    Node* rightLCA = LCAOptimized(root->right, n1, n2);

    if(leftLCA && rightLCA) {
        return root;
    }

    if(leftLCA!=NULL)
    return leftLCA;
    return rightLCA;
}

int Distance(Node* root, int k, int dist) {

    if(root==NULL) {
        return -1;
    }

    if(root->data==k) {
        return dist;
    }

    int left = Distance(root->left, k, dist+1);
    
    if(left!=-1) {
        return left;
    }

    return Distance(root->right, k, dist+1);
}

int distanceBetweenNodes(Node* root, int n1, int n2) {

    Node* lca = LCAOptimized(root, n1, n2);

    int d1 = Distance(lca, n1, 0);
    int d2 = Distance(lca, n2, 0);

    return d1+d2;
}

void flatten(Node* root) {

    if(root==NULL || (root->left==NULL && root->right==NULL))
    return;

    if(root->left) {

        flatten(root->left);

        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node* tail = root->right;

        while(tail->right!=NULL)
        tail = tail->right;

        tail->right = temp;
    }

    if(root->right)
    flatten(root->right);
}

void printSubTreeAtK(Node* root, int k) {

    if(root==NULL || k<0)
    return;

    if(k==0) {

        cout<<root->data<<" ";
        return;
    }

    printSubTreeAtK(root->left, k-1);
    printSubTreeAtK(root->right, k-1);
}

int printNodesAtK(Node* root, Node* target, int k) {

    if(root==NULL) {
        return -1;
    }

    if(root==target) {
        printSubTreeAtK(root, k);
        return 1;
    }

    int ld = printNodesAtK(root->left, target, k);

    if(ld!=-1) {

        if(ld==k) 
        cout<<root->data<<" ";

        if(ld<k)
        printSubTreeAtK(root->right, k-ld-1);

       return ld+1;
    }

     int rd = printNodesAtK(root->right, target, k);

    if(rd!=-1) {

        if(rd==k) 
        cout<<root->data<<" ";

        if(rd<k)
        printSubTreeAtK(root->left, k-rd-1);

       return rd+1;
    }

    return -1;
}

Node* Target(Node* root, int key) {

    if(root==NULL)
    return NULL;

    if(root->data==key)
    return root;

   Node* ln = Target(root->left, key);
   Node* rn = Target(root->right, key);

   if(ln!=NULL)
   return ln;

   if(rn!=NULL)
   return rn;

   return NULL;
}

int maxSum(Node* root) {

    if(root==NULL)
    return 0;


    int lSum = maxSum(root->left);
    int rSum = maxSum(root->right);

    int maxCurr = max(lSum, rSum);

    int maxSum = maxCurr + root->data;

    return maxSum;
}

int maxPathSumUtil(Node* root, int &ans) {

    if(root==NULL)
    return 0;

    int left = maxPathSumUtil(root->left, ans);
    int right = maxPathSumUtil(root->right, ans);

    int maxNode = max(max(root->data, root->data + left + right), max(root->data + left, root->data + right));

    ans = max(ans, maxNode);

    return max(root->data, max(root->data + left, root->data + right));
}

int maxPathSum(Node* root) {

    if(root==NULL)
    return 0;

    int ans = INT64_MIN;

    maxPathSumUtil(root, ans);

    return ans;
}

void inorderPrint(Node* root) {

    if(root==NULL) {
        return;
    }

    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}



int main() {

     system("clear");

    int inorder[] = {4, 12, 1, 5, 3, 6};
    int postorder[] = {4, 12, 5, 6, 3, 1};

    Node* root = build_Tress_post(postorder, inorder, 0, 5);

    // Node*root = new Node(5);
    // root->left = new Node(6);                                          
    // root->right = new Node(3);
    // root->left->left = new Node(9);
    // root->right->right = new Node(1);
    // root->left->right = new Node(1);
    // root->right->left = new Node(2);
    // root->left->right->left = new Node(2);
    // root->right->left->right = new Node(6);
    // root->right->left->right->right = new Node(7);
    // root->left->right->left->left = new Node(3);
    // root->left->right->left->right = new Node(5); 

    cout<<maxPathSum(root);

    cout<<endl;

    return 0;
}