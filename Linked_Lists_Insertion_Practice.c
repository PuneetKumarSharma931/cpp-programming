//Linked_List_Insertion_Practice

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void Traversal(struct Node *head) {
    struct Node *ptr=head;

    while((ptr->next)!=NULL)
    {
        printf("\n%d",ptr->data);
        ptr=ptr->next;
    }

    printf("\n%d",ptr->data);
    
}

struct Node* insertBegin(struct Node *head, int data) {
    struct Node *ptr;
    ptr=(struct Node*)malloc(sizeof(struct Node));

    ptr->data=data;

    ptr->next=head;

    return ptr;
}

struct Node* insertBetween(struct Node *head, int data, int index) {
    struct Node *ptr;
    ptr=(struct Node*)malloc(sizeof(struct Node));

    struct Node *p;
    p=head;
    ptr->data=data;
    int i=0;
    while(i!=index-1) {
        p=p->next;
        i++;
    }

    ptr->next=p->next;
    p->next=ptr;

    return head;
}

struct Node* insertGiven(struct Node *head, int data, struct Node *ptr) {
    struct Node *New;
    New = (struct Node*)malloc(sizeof(struct Node));
    New->data=data;

    New->next=ptr->next;
    ptr->next=New;

    return head;
}

struct Node* insertEnd(struct Node *head, int data) {
    struct Node *ptr;
    ptr= (struct Node*)malloc(sizeof(struct Node));
    struct Node *p=head;
    ptr->data=data;

    while((p->next)!=NULL) {
        p=p->next;
    }

    p->next=ptr;
    ptr->next=NULL;

    return head;

}

int main() {

    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data=22;
    head->next=second;

    second->data=32;
    second->next=third;

    third->data=42;
    third->next=NULL;

    printf("\nNodes before insertion\n");
    Traversal(head);


    head = insertEnd(head, 62);

    printf("\nNodes after insertion\n");
    Traversal(head);

    return 0;


}