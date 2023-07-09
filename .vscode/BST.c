
#include <stdio.h>
#include <stdlib.h>

struct Node {
    
    struct Node* left;
    int data;
    struct Node* right;

};

struct Stack {
    
    struct Node* node;
    struct Stack* next;
};

struct Stack *top = NULL;

struct Node *root = NULL;

void create();
void insert(int);
void rPreorder(struct Node*);
void rInorder(struct Node*);
void rPostorder(struct Node*);
void nrPreorder(struct Node*);

int isEmpty();
void push(struct Node*);
struct Stack* pop();

int main()
{
    int ich;
    char cChoice;
    int iFlag = 0;
    int data;
    struct Node* ptr;
    
    do{
        
        system("clear");
        
        printf("\nWelcome!!");
        printf("\n\nBinary Search Tree Menu");
        printf("\n1.Creation of BST");
        printf("\n2.Insert a Node in BST");
        printf("\n3.Recursive Preorder Traversal");
        printf("\n4.Recursive Inorder Traversal");
        printf("\n5.Recursive Postorder Traversal");
        printf("\n6.Non-Recursive Preorder Traversal");
        printf("\n7.Non-Recursive Inorder Traversal");
        printf("\n8.Non-Recursive Postorder Traversal");
        printf("\n9.Exit");
        
        printf("\nPlease Input your Choice: ");
        scanf("%d",&ich);
        
        switch(ich) {
            
            case 1: if(iFlag == 0) {
                
                        create();
                        iFlag++;
                    }
                    else {
                        
                        printf("\nYou have already created the Tree please find other ways to insert more Nodes!!");
                    }
                    break;
                    
            case 2: system("clear");
            
                    printf("\nPlease Input data to be inserted into the BST: ");
                    scanf("%d",&data);
                    
                    insert(data);
                    
                    printf("\nNode Successfully Inserted into the BST!!");
                    
                    break;
                    
            case 3: ptr = root;
            
                    system("clear");
            
                    printf("\nPreorder Traversal of BST is\n");
                    
                    rPreorder(ptr);
                    break;
                    
            case 4: ptr = root;
                    
                    system("clear");
            
                    printf("\nInorder Traversal of BST is\n");
                    
                    rInorder(ptr);
                    break;
                    
            case 5: ptr = root;
                    
                    system("clear");
            
                    printf("\nPostorder Traversal of BST is\n");
                    
                    rPostorder(ptr);
                    break;
                    
            case 6: ptr = root;
                    
                    system("clear");
                    
                    printf("\nNon-Recursive Preorder Traversal of BST is\n");
                    
                    nrPreorder(ptr);
                    
                    break;
                    
        
        }
        
        printf("\n\nDo you want to continue?(y->yes): ");
        scanf(" %c",&cChoice);
        
    }while(cChoice=='y'||cChoice=='Y');

    return 0;
}

void create() {
    
    int iData;
    char cChoice;
    
    do{
        
        system("clear");
        
        printf("\nPlease input data to be inserted: ");
        scanf("%d",&iData);
        
        insert(iData);
        
        printf("\nNode Successfully Inserted!!");
        
        printf("\nDo you want to insert more nodes in BST?(y->yes): ");
        scanf(" %c",&cChoice);
        
    }while(cChoice=='y'||cChoice=='Y');
    
    printf("\n\nBST Successfully Created!!");
}

void insert(int data) {
    
    struct Node *current, *parent;
    struct Node *nw = (struct Node*)malloc(sizeof(struct Node));
    
    nw->data = data;
    nw->left = NULL;
    nw->right = NULL;
    
    if(root == NULL) {
        
        root = nw;
        return;
    }
    else {
        
        current = root;
        parent = NULL;
        
        while(1) {
            
            parent = current;
            
            if(data<current->data) {
                
                current = current->left;
                
                if(current==NULL) {
                parent->left = nw;
                return;
                }
            }
            else {
                
                current = current->right;
                
                if(current==NULL) {
                parent->right = nw;
                    
                return;
                
                }
            }
        }
    }
    
}

void rPreorder(struct Node* ptr) {
    
    if(ptr!=NULL) {
        
        printf(" %d",ptr->data);
        rPreorder(ptr->left);
        rPreorder(ptr->right);
    } 
}

void rInorder(struct Node* ptr) {
    
    if(ptr!=NULL) {
        
        rInorder(ptr->left);
        printf(" %d",ptr->data);
        rInorder(ptr->right);
    } 
}

void rPostorder(struct Node* ptr) {
    
    if(ptr!=NULL) {
        
        rPostorder(ptr->left);
        rPostorder(ptr->right);
        printf(" %d",ptr->data);
    } 
}

void nrPreorder(struct Node *ptr) {
    
    if(ptr==NULL) 
    printf("\nBST is Empty!!");
    
    struct Stack *temp;
    
    push(ptr);
    
    while(!isEmpty()) {
        
        temp = pop();
        
        printf("%d ",temp->node->data);
        
        push(temp->node->right);
        push(temp->node->left);
        
    }
    
    
}

int isEmpty() {
    
    if(top==NULL)
    return 1;
    return 0;
}

void push(struct Node *Root) {
    
    struct Stack *nw = (struct Stack*)malloc(sizeof(struct Stack));
    
    nw->node = Root;
    nw->next = NULL;
    
    if(top==NULL) {
        
        top=nw;
    }
    else {
        
        struct Stack *ptr = top;
        
        while(ptr->next!=NULL)
        ptr = ptr->next;
        
        ptr->next = nw;
        
    }
}

struct Stack* pop() {
    
    if(isEmpty()) {
        
        return NULL;
    }
    else {
        
        struct Stack* temp = top;
        top = top->next;
        
        return temp;
    }
}



