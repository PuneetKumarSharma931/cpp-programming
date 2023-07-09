//Multiple_Parenthesis Matching

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int isOperator(char ch) {
    if((ch=='(') || (ch==')') || (ch=='+') || (ch=='-') || (ch=='/') || (ch=='*')) 
    return 1;
    return 0; 
}

int prec(char ch) {
    if((ch=='+') || (ch=='-')) 
    return 1;

    if((ch=='/') || (ch=='*'))
    return 2;
    return 0;
}

char* intopost(char *infix) {
    char *postfix = (char*)malloc((strlen(infix)+1)*sizeof(char));

    struct Stack *sp = (struct Stack*)malloc(sizeof(struct Stack));
    sp->top = -1;
    sp->size = 100;
    sp->arr = (char*)malloc(sp->size*sizeof(char));

    int i = 0;
    int j = 0;
    char ch;

    while(infix[i]!='\0') {
        if(!isOperator(infix[i])) {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else {
            if(sp->top==-1) {
                push(sp, infix[i]);
                i++;
            }
            else {
            if(infix[i]=='(') {
                push(sp, infix[i]);
                i++;
            }
            else if(infix[i]==')') {
                while((ch = pop(sp))!='(') {
                    postfix[j] = ch;
                    j++;
                }
                i++;
            }
            else if(sp->arr[sp->top]=='(') {
                push(sp, infix[i]);
                i++;
            }
            else {
                if(prec(infix[i])>prec(sp->arr[sp->top])) {
                    push(sp, infix[i]);
                    i++;
                }
                else {
                    while((prec(infix[i])<=prec(sp->arr[sp->top]))&&(sp->top!=-1)) {
                        ch = pop(sp);
                        postfix[j] = ch;
                        j++;
                    }
                    if(sp->top==-1){
                        push(sp, infix[i]);
                        i++;
                    }
                    else {
                        push(sp, infix[i]);
                        i++;
                    }
                
                }
            }
            
        }

        }
    }

    if(!isEmpty(sp)) {
        while(!isEmpty(sp)) {
            postfix[j] = pop(sp);
            j++;
        }
    }

    postfix[j] = '\0';

    return postfix;
}

int main() {

    system("clear");

    char exp[] = {"A+(B-C*(C-D/F))*(F-G)"};

    printf("%s",intopost(exp));
    


    return 0;


}