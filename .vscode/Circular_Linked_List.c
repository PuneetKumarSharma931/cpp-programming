/*Name of the Experiment: Lab Assignment - 9
Student Name: Puneet Kumar Sharma
Student Enrollment No: A2305220749
Student Class(Batch): 3CSE9(Y)
Variables Used: Node is a structure having next pointer of type Node and data of type integer to store data for the list, head is a pointer of type Node which will always points at the first Node of the Circular Linked List, ich of type integer is used to get user's choice for the CLL menu, cChoice of type char is used to get user's
choice of continuing with the program or not, iFlag of type integer is used as a  Flag variable so that user will only able to create CLL once, nw pointer of type Node is used everywhere in the program to create new nodes, ptr pointer of type Node is used everywhere in the program to be used as a reference so that operations on lists can be performed,
count of type ineteger is used to count number of nodes in the CLL, ind and pos of type integer are used to get user's input of position to insert or delete a node from the list, iLoop of type integer is used as a loop variable, temp pointer of type Node is used everywhere as a temporary pointer so that Nodes can be deleted or data of the Nodes can be swapped,
ptri and ptrj of type Node are pointers to traverse CLL for the purpose of sorting it.
Functions Used: createCLL() function is used to create a Circular Linked List from user's input data only once, displayCLL() function is used to display CLL from beginning to end, countCLL() function is used to count the number of nodes in CLL, insertBegin() function is used to insert nodes in the list at first position, insertSpecific() function is used to insert Nodes at the position given by the user,
insertEnd() function is used to insert Nodes at the end of the CLL, deleteBegin() function is used to delete Nodes from the beginning, deleteSpecific() function is used to delete Nodes from the list whose position is given by the user, deleteEnd() function is used to delete Nodes from the End in the CLL, sortCLL() function is used to sort the CLL in ascending order.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void createCLL();
void displayCLL();
void countCLL();
void insertBegin();
void insertSpecific();
void insertEnd();
void deleteBegin();
void deleteEnd();
void deleteSpecific();
void sortCLL();

struct Node *head = NULL;

int main()
{
    int iCh;
    char cChoice;
    int flag = 0;
    
    do {
        system("clear");
        printf("\nWelcome!!!\n");
        printf("\nCircular Linked List");
        printf("\n1. Create a CLL");
        printf("\n2. Insertion in CLL");
        printf("\n3. Deletion in CLL");
        printf("\n4. Count the number of Nodes in CLL");
        printf("\n5. Sort CLL");
        printf("\n6. Display CLL");
        printf("\n7. Exit");
        
        printf("\nPlease Input your Choice: ");
        scanf("%d",&iCh);
        
        switch(iCh) {
            
            case 1: if(flag == 0) {
                    createCLL();
                    flag++;
                
                }
                    else{
                        printf("\nCLL is already created please find other ways to input more nodes!");
                    }
                    break;
                    
            case 2: 
                    do {
                        system("clear");
                        printf("\nInsertion in CLL");
                        printf("\n1. Insert at beginning");
                        printf("\n2. Insert at specific position");
                        printf("\n3. Insert at end");
                        
                        printf("\n\nInput your choice: ");
                        scanf("%d",&iCh);
                        
                        switch(iCh) {
                            case 1: insertBegin();
                                    break;
                                    
                            case 2: insertSpecific();
                                    break;
                                    
                            case 3: insertEnd();
                                    break;
                        }
                        
                            printf("\nDo you want to continue?(y->yes): ");
                            scanf(" %c",&cChoice);
                        }while((cChoice=='y')||(cChoice=='Y'));
                        break;
                        
            case 3: 
                    do {
                        system("clear");
                        printf("\nDeletion in CLL");
                        printf("\n1. Delete from beginning");
                        printf("\n2. Delete from specific position");
                        printf("\n3. Delete from end");
                        
                        printf("\n\nInput your choice: ");
                        scanf(" %d",&iCh);
                        
                        switch(iCh) {
                            case 1: deleteBegin();
                                    break;
                                    
                            case 2: deleteSpecific();
                                    break;
                                    
                            case 3: deleteEnd();
                                    break;
                        }
                        
                            printf("\nDo you want to continue?(y->yes): ");
                            scanf(" %c",&cChoice);
                        }while((cChoice=='y')||(cChoice=='Y'));
                        break;
                    
            case 4: countCLL();
                    break;
                    
            case 5: sortCLL();
                    break;
            
            case 6: displayCLL();
                    break;
                    
            case 7: exit(0);
                    break;
                    
            default: printf("\nWrong Choice!!!");
                    
                    
           }
        
        printf("\nDo you want to continue?(y->yes): ");
        getchar();
        scanf("%c",&cChoice);
    }while((cChoice!='N')||(cChoice!='n'));

    return 0;
}

void createCLL() {
    
    char ch;
    struct Node *nw;
    struct Node *ptr;
    
    do{
        system("clear");
        
        nw = (struct Node*)malloc(sizeof(struct Node));
        
        printf("\nInput Data in the Node:");
        scanf("%d",&nw->data);
        nw->next = NULL;
        
        if(head==NULL) {
            head = nw;
            nw->next = head;
        }
        else {
            for(ptr=head;ptr->next!=head;ptr=ptr->next);
            ptr->next = nw;
            nw->next = head;
        }
        
        printf("\nNode Successfully Added!!!");
        
        printf("\nDo you want to add more Nodes?(y->yes):");
        scanf(" %c",&ch);
        
    }while(ch=='y'||ch=='Y');
}

void displayCLL() {
    
    struct Node *ptr = head;
    
    system("clear");
    
    if(ptr==NULL) {
        printf("\nError!! List is empty Nothing to Display\n");
    }
    else {
        printf("\nhead-->%u\n",head);
        printf("\nCurrent Linked List\n");
        
        while(ptr->next!=head) {
            printf("|%d|%u|-->",ptr->data,ptr->next);
            ptr = ptr->next;
        }
        
        printf("|%d|%u|",ptr->data,head);
        
    }
}

void countCLL() {
    
    int count = 0;
    struct Node *ptr = head;
    
    system("clear");
    
    if(head==NULL) {
        
        printf("\nCurrent Nodes in List: %d",count);
    }
    else {
        do {
            count++;
            ptr = ptr->next;
        }while(ptr!=head);
        
        printf("\bCurrent Nodes in List: %d",count);
    }
}

void insertBegin() {
    
    system("clear");
    
    struct Node *nw = (struct Node*)malloc(sizeof(struct Node));
    
    printf("\nInput data you want to insert in the list: ");
    scanf("%d",&nw->data);
    nw->next = NULL;
    
    if(head == NULL) {
        head = nw;
        nw->next = head;
    }
    else {
        nw->next = head;

        struct Node* ptr = head;

        while(ptr->next!=head)
        ptr=ptr->next;

        head = nw;
        ptr->next = head;
        
    }
    
    printf("\n1 Node successfully inserted in the beginning!!");
    
}

void insertSpecific() {
    
    int ind;
    int iLoop = 1;
    
    struct Node *nw = (struct Node*)malloc(sizeof(struct Node));
    struct Node *ptr = head;
    
    system("clear");
    
    printf("\nInput data to be inserted in the list: ");
    scanf("%d",&nw->data);
    nw->next = NULL;
    
    printf("\n\nAfter which Node you want to insert this Node?: ");
    scanf("%d",&ind);
        
        while(iLoop<ind) {
            
            ptr = ptr->next;
            ++iLoop;
        }
        
        nw->next = ptr->next;
        ptr->next = nw;
        
        printf("\n1 Node successfully Inserted!!");
}

void insertEnd() {
    
    struct Node *nw = (struct Node*)malloc(sizeof(struct Node));
    struct Node *ptr = head;
    
    system("clear");
    
    printf("\nInput data to be inserted in the list: ");
    scanf("%d",&nw->data);
    nw->next = NULL;
    
    while(ptr->next!=head) {
        ptr = ptr->next;
    }
    
    ptr->next = nw;
    nw->next = head;
    
    printf("\n1 Node successfully Inserted!!");
    
}

void deleteEnd() {
    
    system("clear");
    
    if(head == NULL) {
        printf("\nError!! List is already empty..");
    }
    else {
            struct Node *ptr = head;
            struct Node *temp;
            
            if(head->next==head){
                
                printf("\nDeleted node from list is |%d|%u|",head->data,head);
                head = NULL;
                free(ptr);
            }
            else {
                while((ptr->next->next)!=head) {
                    ptr=ptr->next;
                }
                temp = ptr->next;
                ptr->next = head;
                printf("\nDeleted node from list is |%d|%u|",temp->data,head);
                free(temp);
                
            }
        
    }
}

void deleteBegin() {
    
    system("clear");
    
    if(head == NULL) {
        printf("\nError!! List is already empty..");
    }
    else {
            struct Node *ptr = head;
            
            if(head->next==head){
                
                printf("\nDeleted node from list is |%d|%u|",head->data,head);
                head = NULL;
                free(ptr);
            }
            else {
                
                struct Node* temp = head;

                while(temp->next!=head)
                temp=temp->next;

                head = head->next;
                temp->next = head;
                
                printf("\nDeleted node from list is |%d|%u|",ptr->data,ptr->next);
                
                free(ptr);
            }
        
    }
    
    
}


void deleteSpecific() {
    
    int pos;
    
    system("clear");
    
    if(head==NULL) {
        
        printf("\nError!! List is already empty..");
    }
    else {
        printf("\nInput the position at which you want to delete the Node: ");
        scanf("%d",&pos);
        
        struct Node *ptr = head;
        struct Node *temp;
        
        for(int i=1;i<pos-1;i++) {
            ptr = ptr->next;
        }
        
        temp = ptr->next;
        ptr->next = ptr->next->next;
        printf("\nDeleted node from list is |%d|%u|",temp->data,temp->next);
        free(temp);

    }
}

void sortCLL() {
    
    struct Node *ptri = head;
    struct Node *ptrj;
    int temp;
    
    do {
        
        ptrj = ptri->next;
        
        while(ptrj!=head) {
            
            if(ptri->data>ptrj->data) {
                
                temp = ptri->data;
                ptri->data = ptrj->data;
                ptrj->data = temp;
            }
            
            ptrj = ptrj->next;
    }
    
    ptri = ptri->next;
}while(ptri!=head);

    printf("\n\nCLL Successfully Sorted...");
}






