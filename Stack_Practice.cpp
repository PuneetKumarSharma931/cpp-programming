
#include<iostream>
#include<stack>
#include<math.h>
#include<algorithm>

using namespace std;

void reverseSentence(string s) {

    stack<string> st;
    string word;

    for(int i=0;i<s.length();i++) {

        word = "";

        while(s[i]!=' ' && i<s.length()) {

            word+=s[i];
            i++;
        }

        st.push(word);
    }

    while(!st.empty()) {

        cout<<st.top()<<" ";
        st.pop();
    }
}

void insertAtBottom(stack<int> &st, int ele) {

    if(st.empty()) {
        
        st.push(ele);
        return;
    }

    int topele = st.top();
    st.pop();
    insertAtBottom(st, ele);

    st.push(topele);
}

void reverseStack(stack<int> &st) {

    if(st.empty()) {
        return;
    }

    int ele = st.top();
    st.pop();
    reverseStack(st);

    insertAtBottom(st, ele);
}

int prefixEvaluation(string str) {

    int op1;
    int op2;
    stack<int> st;

    for(int i=str.length()-1;i>=0;i--) {

        if(str[i]>='0' && str[i]<='9') {

            st.push(str[i]-'0');
        }
        else {

            op1 = st.top();
            st.pop();
            op2 = st.top();
            st.pop();

            switch(str[i]) {

                case '+': st.push(op1+op2);
                            break;

                case '-': st.push(op1-op2);
                            break;

                case '*': st.push(op1*op2);
                            break;

                case '/': st.push(op1/op2);
                            break;

                case '^': st.push(pow(op1,op2));
                            break;
            }
        }
        
    }

    return st.top();
}

int postfixEvaluation(string str) {

    stack<int> st;
    int op1;
    int op2;

    for(int i=0;i<str.length();i++) {

        if(str[i]>='0' && str[i]<='9') {

            st.push(str[i]-'0');
        }
        else {

            op2 = st.top();
            st.pop();
            op1 = st.top();
            st.pop();

            switch(str[i]) {

                case '+': st.push(op1+op2);
                            break;

                case '-': st.push(op1-op2);
                            break;

                case '*': st.push(op1*op2);
                            break;

                case '/': st.push(op1/op2);
                            break;

                case '^': st.push(pow(op1, op2));
                            break;
            }
        }
    }

    return st.top();
}

int precedence(char ch) {

    if(ch=='^') {
        return 3;
    }
    else if(ch=='*' || ch=='/') {
        return 2;
    }
    else if(ch=='+' || ch=='-') {
        return 1;
    }
    else {
        return -1;
    }
}

string infixToPostfix(string str) {


    string result;

    stack<char> st;

    for(int i=0;i<str.length();i++) {

        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')) {

            result+=str[i];
        }
        else if(str[i]=='(') {
            st.push(str[i]);
        }
        else if(str[i]==')') {

            while(!st.empty() && st.top()!='(') {

                result+=st.top();
                st.pop();
            }
            if(!st.empty()) {

                st.pop();
            }
        }
        else {

            while(!st.empty() && precedence(st.top())>precedence(str[i])) {

                result+=st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }

    while(!st.empty()) {

        result+=st.top();
        st.pop();
    }

    return result;
}

string infixToPrefix(string str) {

    reverse(str.begin(), str.end());

    string result;
    stack<char> st;

    for(int i=0;i<str.length();i++) {

        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')) {

            result+=str[i];
        }
        else if(str[i]==')') {
            st.push(str[i]);
        }
        else if(str[i]=='(') {

            while(!st.empty() && st.top()!=')') {
                result+=st.top();
                st.pop();
            }
            if(!st.empty()) {

                st.pop();
            }
        }
        else {

            while(!st.empty() && precedence(st.top())>precedence(str[i])) {

                result+=st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }

    while(!st.empty()) {

        result+=st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());

    return result;
}

bool isValid(string str) {

    stack<char> st;

    for(int i=0;i<str.length();i++) {

        if(str[i]=='(' || str[i]=='{' || str[i]=='[') {

            st.push(str[i]);
        }
        else if(str[i]==')') {

            if(!st.empty() && st.top()=='(') {

                st.pop();
            }
            else {

                return false;
            }
        }
        else if(str[i]=='}') {

            if(!st.empty() && st.top()=='{') {

                st.pop();
            }
            else {

                return false;
            }
        }
        else if(str[i]==']') {
            
            if(!st.empty() && st.top()=='[') {

                st.pop();
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if(st.empty())
    return true;
    return false;
    
}

int main() {

    system("clear");

    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    if(isValid("{[)}]")) {

        cout<<"The String is valid";
    }
    else {

        cout<<"The String is inValid";
    }

    return 0;
}