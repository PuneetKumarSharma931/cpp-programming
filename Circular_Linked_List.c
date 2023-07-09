
//Circular_Linked_List_Practice

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void Traversal(struct Node *head) {
    struct Node *ptr=head;

    while((ptr->next)!=head)
    {
        printf("\n%d",ptr->data);
        ptr=ptr->next;
    }

    printf("\n%d",ptr->data);
    
}

struct Node* insertBegin(struct Node *head, int data) {
    struct Node *ptr;

    ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;

    struct Node *p=head->next;

    while(p->next!=head) {
        p=p->next;
    }

    p->next=ptr;
    ptr->next=head;
    head=ptr;

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
    third->next=head;

    printf("\nNodes before Insertion\n");
    Traversal(head);

    head = insertBegin(head, 62);
    head = insertBegin(head, 200);
    head = insertBegin(head, 300);
    head = insertBegin(head, 400);

    printf("\nNodes after Insertion\n");
    Traversal(head);

    return 0;
}