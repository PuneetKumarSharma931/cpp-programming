#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

bool redunant_paranthesis(string str)
{

    stack<char> st;
    bool ans = false;

    for(int i=0;i<str.size();i++) {

        if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='(') {

            st.push(str[i]);
        }
        else if(str[i]==')') {

            if(st.top()=='(') {

                ans = true;
            }
            while(st.top()=='+' || st.top()=='-' || st.top()=='*' || st.top()=='/') {

                st.pop();
            }
            st.pop();
        }
    }

    return ans;
}

int main()
{

    system("clear");

    string str = "(a+((b+c)*(a/(g+e))))";

    if (!redunant_paranthesis(str))
    {

        cout << endl
             << "The expression does not have redundant paranthesis!";
    }
    else
    {
        cout << endl
             << "The expression have redundant paranthesis!";
    }

    return 0;
}