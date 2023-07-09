
//Queue Using Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void Traversal(struct Node *ptr) {
    if(ptr==NULL) {
        printf("\nQueue is Empty!!");
    }
    else {
        while(ptr!=NULL) {
            printf("\nElement: %d",ptr->data);
            ptr = ptr->next;
        }
    }
}

void enqueue(struct Node **f, struct Node **r, int val) {

    struct Node *new = (struct Node*)malloc(sizeof(struct Node));

    if(new==NULL) {
        printf("\nQueue is Full!!");
    }
    else {
        new->data = val;
        new->next = NULL;
        if(*f==NULL) {
            *f = *r = new;
        }
        else {
            (*r)->next = new;
            *r = new;
        }
    }
}

int dequeue(struct Node **f) {

    struct Node *ptr = *f;
    int val;

    if(*f==NULL) {
        printf("\nQueue is Empty!!");
        return -1;
    }
    else {
        ptr = *f;
        *f=(*f)->next;
        val = ptr->data;
        free(ptr);
        return val;
    }
}

int main() {
    struct Node *f = NULL;
    struct Node *r = NULL;

    system("clear");

    char ch = 'y';
    int val;

    while((ch=='y') || (ch=='Y')) {

        system("clear");

        printf("\nInput Element: ");
        scanf("%d",&val);

        enqueue(&f, &r, val);
        Traversal(f);

        printf("\nDo you want to Continue?: ");
        fflush(stdin);
        scanf("%c",&ch);
    }

    ch = 'y';

    while((ch=='y') || (ch=='Y')) {

        system("clear");

        printf("\nDequeued Element: %d",dequeue(&f));

        Traversal(f);

        printf("\nDo you want to Continue?: ");
        fflush(stdin);
        scanf("%c",&ch);
    }

    return 0;

}