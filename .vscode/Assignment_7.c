
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void createSLL();
void displaySLL();
void countSLL();
void insertBegin();
void insertSpecific();
void insertEnd();
void deleteBegin();
void deleteEnd();
void deleteSpecific();
void sortSLL();

struct Node *head = NULL;

int main()
{
    int iCh;
    char cChoice;
    
    do {
        system("clear");
        printf("\nWelcome!!!\n");
        printf("\nSingly Linked List");
        printf("\n1. Create a SLL");
        printf("\n2. Insertion in SLL");
        printf("\n3. Deletion in SLL");
        printf("\n4. Count the number of Nodes in SLL");
        printf("\n5. Sort SLL");
        printf("\n6. Display SLL");
        printf("\n7. Exit");
        
        printf("\nPlease Input your Choice: ");
        scanf("%d",&iCh);
        
        switch(iCh) {
            
            case 1: createSLL();
                    break;
                    
            case 2: 
                    do {
                        system("clear");
                        printf("\nInsertion in SLL");
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
                        printf("\nDeletion in SLL");
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
                    
            case 4: countSLL();
                    break;
                    
            case 5: sortSLL();
                    break;
            
            case 6: displaySLL();
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

void createSLL() {
    
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
        }
        else {
            for(ptr=head;ptr->next!=NULL;ptr=ptr->next);
            ptr->next = nw;
        }
        
        printf("\nNode Successfully Added!!!");
        
        printf("\nDo you want to add more Nodes?(y->yes):");
        scanf(" %c",&ch);
        
    }while(ch=='y'||ch=='Y');
}

void displaySLL() {
    
    struct Node *ptr = head;
    
    system("clear");
    
    if(ptr==NULL) {
        printf("\nError!! List is empty Nothing to Display\n");
    }
    else {
        printf("\nhead-->%u\n",head);
        printf("\nCurrent Linked List\n");
        
        while(ptr->next!=NULL) {
            printf("|%d|%u|-->",ptr->data,ptr->next);
            ptr = ptr->next;
        }
        
        printf("|%d|NULL|",ptr->data);
        
    }
}

void countSLL() {
    
    int count = 0;
    struct Node *ptr = head;
    
    system("clear");
    
    if(head==NULL) {
        
        printf("\nCurrent Nodes in List: %d",count);
    }
    else {
        while(ptr!=NULL) {
            count++;
            ptr = ptr->next;
        }
        
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
    }
    else {
        nw->next = head;
        head = nw;
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
    
    while(ptr->next!=NULL) {
        ptr = ptr->next;
    }
    
    ptr->next = nw;
    
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
            
            if(head->next==NULL){
                
                printf("\nDeleted node from list is |%d|%s|",head->data,"NULL");
                head = NULL;
                free(ptr);
            }
            else {
                while((ptr->next->next)!=NULL) {
                    ptr=ptr->next;
                }
                temp = ptr->next;
                ptr->next = NULL;
                printf("\nDeleted node from list is |%d|%s|",temp->data,"NULL");
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
            
            if(head->next==NULL){
                
                printf("\nDeleted node from list is |%d|%s|",head->data,"NULL");
                head = NULL;
                free(ptr);
            }
            else {
                
                head = head->next;
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

void sortSLL() {
    
    struct Node *ptri = head;
    struct Node *ptrj;
    int temp;
    
    while(ptri!=NULL) {
        
        ptrj = ptri->next;
        
        while(ptrj!=NULL) {
            
            if(ptri->data>ptrj->data) {
                
                temp = ptri->data;
                ptri->data = ptrj->data;
                ptrj->data = temp;
            }
            
            ptrj = ptrj->next;
    }
    
    ptri = ptri->next;
}



