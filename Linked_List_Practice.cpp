
#include<iostream>

using namespace std;

class node {

    public:

    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

void insert(node* &head, int val) {

    if(head==NULL) {

        node* nw = new node(val);
        head = nw;
    }
    else {

        node* temp = head;
        node* nw = new node(val);

        while(temp->next!=NULL) {
            temp = temp->next;
        }

        temp->next = nw;
    }
}

void display(node* head) {

    node* temp = head;

    while(temp!=NULL) {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}

node* appendk(node* &head, int k) {

    node* newHead;
    node* newTail;
    node* tail = head;
    int count = 1;
    int l = 0;

    node* temp = head;

    while(temp!=NULL) {
        temp = temp->next;
        l++;
    }

    while(tail->next!=NULL) {

        if(count==l-k) {
            newTail = tail;
            tail = tail->next;
            count++;
        }
        else if(count==l-k+1) {
            newHead = tail;
            tail = tail->next;
            count++;
        }
        else {
            tail = tail->next;
            count++;
        }
    }

    newTail->next = NULL;
    tail->next = head;
    return newHead;
}

void intersect(node* &head1, node* &head2, int pos) {

    node* temp1 = head1;
    node* temp2 = head2;
    pos--;

    while(pos--) {

        temp1 = temp1->next;
    }

    while(temp2->next!=NULL) {
        temp2 = temp2->next;
    }

    temp2->next = temp1;
}

int length(node* head) {

    int l = 0;
    node* temp = head;

    while(temp!=NULL) {
        temp = temp->next;
        l++;
    }

    return l;
}

int intersection(node* &head1, node* &head2) {

    int l1;
    int l2;
    node* ptr1 = head1;
    node* ptr2 = head2;
    int d = 0;

    l1 = length(head1);
    l2 = length(head2);

    if(l1>l2) {
        d = l1-l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else {
        d = l2-l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    if(d>length(ptr1)){
        return -1;
    }

    while(d) {
        ptr1 = ptr1->next;
        d--;
    }

    while(ptr1!=NULL && ptr2!=NULL) {

        if(ptr1 == ptr2) {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;


}

node* merge(node* &head1, node* &head2) {

    node* ptr1 = head1;
    node* ptr2 = head2;
    node* dummyNode = new node(-1);

    node* ptr3 = dummyNode;

    while(ptr1!=NULL && ptr2!=NULL) {
    if(ptr1->data<ptr2->data) {

        ptr3->next = ptr1;
        ptr1 = ptr1->next;
    }
    else {

        ptr3->next = ptr2;
        ptr2 = ptr2->next;
    }

    ptr3 = ptr3->next;
    }

    while(ptr1!=NULL) {

        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }

    while(ptr2!=NULL) {

        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }

    return dummyNode->next;

}

node* recursiveMerge(node* &head1, node* &head2) {

    node* result;

    if(head1==NULL)
    return head2;

    if(head2==NULL)
    return head1;

    if(head1->data<head2->data) {

        result = head1;
        result->next = recursiveMerge(head1->next, head2);
    }
    else {

        result = head2;
        result->next = recursiveMerge(head1, head2->next);
    }

    return result;
}

node* evenAfterOdd(node* &head) {

    node* odd = head;
    node* even = head->next;
    node* evenStart = even;

    while(odd->next!=NULL && even->next!=NULL) {

        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    if(odd->next==NULL) {
        even->next = NULL;
    }

    odd->next = evenStart;

    return head;
}

int main() {

    system("clear");

    node* head = NULL;
    node* head2 = NULL;

    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    insert(head2,7);
    insert(head2, 8);
    insert(head2, 9);

    display(head);

    cout<<endl;

    display(head2);

    cout<<endl;

    head = evenAfterOdd(head);

    display(head);

    return 0;
}