
//Multiple_Parenthesis Matching

#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    int size;
    char *arr;
};

int isFull(struct Stack *ptr) {
    if((ptr->top)==(ptr->size-1)) {
        return 1;
    }
    return 0;
}

int isEmpty(struct Stack *ptr) {
    if(ptr->top==-1) {
        return 1;
    }
    return 0;
}

void push(struct Stack *S, char ch) {
    if(isFull(S)) {
        printf("\nStack Overflow!!");
    }
    else {
        if(S->top==-1) {
            S->top=0;
            S->arr[S->top] = ch;
        }
        else {
            S->top++;
            S->arr[S->top] = ch;
        }
    }
}

char pop(struct Stack *S) {
    if(isEmpty(S)) {
        printf("\nStack Underflow!!");
        return -1;
    }
    else {
        int ch = S->arr[S->top];
        S->top--;
        return ch;
    }
}

int Match(char a, char b) {
    if((a=='(' && b==')') || (a=='[' && b==']') || (a=='{' && b=='}'))
    return 1;
    return 0;
}

int parenthesisMatching(struct Stack *ptr, char *exp) {
    char ch;
    for(int i=0;exp[i]!='\0';i++) {
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{') {
            push(ptr,exp[i]);
        }
        else if(exp[i]==')' || exp[i]==']' ||exp[i]=='}') {
            if(isEmpty(ptr)) {
                return 0;
            }
            else {
                ch = pop(ptr);
                if(!Match(ch,exp[i]))
                return 0;
            }
        }
    }

    if(isEmpty(ptr))
    return 1;
    return 0;
}

int main() {

      system("clear");
    
    struct Stack *Sp = (struct Stack*)malloc(sizeof(struct Stack));

    Sp->top = -1;
    Sp->size = 100;
    Sp->arr = (char*)malloc(Sp->size*sizeof(char));

    char expression[] = {"{([8*(5-2)]*[(6-(4+*)/6)])}"};

    if(parenthesisMatching(Sp, &expression)) {
        printf("\nParenthesis is Matching");
    }
    else {
        printf("\nParenthesis is Not Matching");
    }


    return 0;


}

