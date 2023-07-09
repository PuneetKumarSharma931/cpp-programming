
//Doubly_Linked_List_Practice

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

void Traversal(struct Node *head) {
    struct Node *ptr;

    ptr = head;

    if(head == NULL) {
        printf("\nLinked List is Empty!!");
    }
    else {
        while(ptr->next!=NULL) {
            printf("\nElement: %d", ptr->data);
            ptr=ptr->next;
        }
        printf("\nElement: %d", ptr->data);

        printf("\nLinked List Back Traversal");

        while(ptr->prev!=NULL) {
            printf("\nElement: %d",ptr->data);
            ptr=ptr->prev;
        }
        printf("\nElement: %d",ptr->data);
    }
}

int main() {
    struct Node *new;
    struct Node *ptr;
    char ch = 'y';

    while(ch=='y'||ch=='Y') {
        system("clear");
        new = (struct Node*)malloc(sizeof(struct Node));
        printf("\nInput Element: ");
        scanf("%d",&new->data);

        new->next = NULL;

        if(head==NULL) {
            head = new;
            new->prev = NULL;
        }
        else {
            ptr = head;
            
            while(ptr->next!=NULL) {
                ptr = ptr->next;
            }

            ptr->next = new;
            new->prev = ptr;
        }

        Traversal(head);

        printf("\n Do you want to add more Nodes?: ");
        fflush(stdin);
        scanf("%c",&ch);
    }

    return 0;
}