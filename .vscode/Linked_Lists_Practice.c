
//Linked Lists Practice

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void Traversal(struct Node *ptr) {

    while((ptr->next)!=NULL)
    {
        printf("\n%d",ptr->data);
        ptr=ptr->next;
    }
    printf("\n%d",ptr->data);
}

int main() {
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data=22;
    head->next=second;

    second->data=32;
    second->next=third;

    third->data=42;
    third->next=fourth;

    fourth->data=52;
    fourth->next=NULL;

    Traversal(head);

    return 0;
}