
//Linked_List_Deletion_Practice

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

struct Node* deleteFirst(struct Node *head) {
    struct Node *ptr=head;

    head=head->next;

    free(ptr);

    return head;
}

struct Node* deleteIndex(struct Node *head, int index) {
    struct Node *p = head;
    struct Node *q = head->next;

    int i=0;

    while(i!=index-2) {
        q=q->next;
        p=p->next;
        i++;
    }

    p->next=q->next;
    free(q);

    return head;

}

struct Node* deleteLast(struct Node *head) {
    struct Node *p = head;
    struct Node *q = head->next;

    while((q->next)!=NULL) {
        q=q->next;
        p=p->next;
    }

    p->next = q->next;
    free(q);

    return head;
}

struct Node* deleteGiven(struct Node *head, int val) {
    struct Node *p = head;
    struct Node *q = head->next;

    while((q->data!=val)&&(q->next!=NULL)) {
        q=q->next;
        p=p->next;
    }

    if((q->data)==val) {
        p->next = q->next;
        free(q);
    }
    else {
        printf("\nElement Does not Exist!!!");
    }

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

    printf("\nNodes before Deletion\n");
    Traversal(head);

    //head = deleteFirst(head);

    //head = deleteIndex(head, 2);

    //head = deleteLast(head);

    head = deleteGiven(head, 32);

    head = deleteGiven(head, 100);

    printf("\nNodes after Deletion\n");
    Traversal(head);

    return 0;
}