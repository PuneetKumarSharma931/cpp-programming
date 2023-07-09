//Stack_Linked_List_Practice

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void Traversal() {
    if(top==NULL) {
        printf("\nStack is Empty!!");
    }
    else {
        struct Node *ptr;
        ptr = top;

        while(ptr!=NULL) {
            printf("\nElement: %d",ptr->data);
            ptr=ptr->next;
        }
    }
}

int isEmpty() {
    if(top==NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int isFull() {
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));

    if(ptr==NULL) {
        free(ptr);
        return 1;
    }
    else {
        free(ptr);
        return 0;
    }
}

void push(int data) {
    if(isFull()) {
        printf("\nStack Overflow!!");
    }
    else {
        struct Node *new = (struct Node*)malloc(sizeof(struct Node));
        new->data = data;
        new->next = top;
        top = new;
    }
}

int pop() {
    if(isEmpty()) {
        printf("\nStack Underflow!!");
        return -1;
    }
    else {
        int x = top->data;
        struct Node *ptr = top;
        top=top->next;
        free(ptr);
        return x;
    }
}

int peek(int pos) {

    struct Node *ptr = top;
    int i =1;

    while((i<=pos-1)&&(ptr!=NULL)) {
        ptr = ptr->next;
        i++;
    }

    if(ptr!=NULL) {
        return ptr->data;
    }
    else {
        return -1;
    }
}

int stacktop() {
    if(isEmpty()) {
        return -1;
    }
    else {
        return top->data;
    }
}

int stackbottom() {
    struct Node *ptr = top;

    if(isEmpty()) {
        return -1;
    }
    else {
        while(ptr->next!=NULL) {
            ptr = ptr->next;
        }

        return ptr->data;
    }
}

int main() {
    char ch='y';
    int val;

    while(ch=='y'||ch=='Y') {
        system("clear");
        printf("\nInput Element: ");
        scanf("%d",&val);
        push(val);
        Traversal();

        printf("\nDo you want to Continue?: ");
        fflush(stdin);
        scanf("%c",&ch);
    }

    ch='y';


    while(ch=='y'||ch=='Y') {
        system("clear");
        printf("\nPeeked Element: %d",peek(3));
        printf("\nStack Top: %d",stacktop());
        printf("\nStack Bottom: %d",stackbottom());
        printf("\nPopped Element: %d",pop());
        Traversal();

        printf("\nDo you want to Continue?: ");
        fflush(stdin);
        scanf("%c",&ch);
    }

    return 0;
}