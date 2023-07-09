
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Queue
{

    stack<int> st1;

public:
    void enqueue(int val)
    {

        st1.push(val);
    }

    int dequeue()
    {

        if (st1.empty())
        {

            cout << "Error! Queue is already empty";
            return -1;
        }

        int ele = st1.top();
        st1.pop();

        if (st1.empty())
        {

            return ele;
        }

        int item = dequeue();

        st1.push(ele);

        return item;
    }

    bool isempty()
    {

        if (st1.empty())
            return true;
        return false;
    }
};

class Stack
{

    queue<int> q1;
    queue<int> q2;
    int N;

public:
    Stack()
    {

        N = 0;
    }

    void push(int val)
    {

        q2.push(val);
        N++;
        while (!q1.empty())
        {

            q2.push(q1.front());
            q1.pop();
        }

        queue<int> temp;
        temp = q1;
        q1 = q2;
        q2 = temp;
    }

    int pop()
    {

        if (!q1.empty())
        {
            N--;
            cout << endl;
            int top = q1.front();
            q1.pop();
            return top;
        }
        return -1;
    }

    int size()
    {

        return N;
    }

    int top()
    {

        return q1.front();
    }
};

class Stack2 {

    queue<int> q1;
    queue<int> q2;
    int N;

    public:

    Stack2() {

        N=0;
    }

    void push(int val) {

        q1.push(val);
        N++;
    }

    int pop() {

        if(q1.empty()) {

            return -1;
        }

        while(q1.size()!=1) {

            q2.push(q1.front());
            q1.pop();
        }

        int ele = q1.front();
        q1.pop();

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        N--;
        return ele;
    }

    int size() {

        return N;
    }

    int top() {

        if(q1.empty()) {

            return -1;
        }

        while(q1.size()!=1) {

            q2.push(q1.front());
            q1.pop();
        }

        int top = q1.front();
        q2.push(q1.front());
        q1.pop();

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;

        return top;
    }
};

int main()
{

    system("clear");

    Stack2 st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << st.pop();
    cout << st.top();
    cout << st.size();

    cout << st.pop();
    cout << st.pop();
    cout << st.pop();
    cout << st.pop();
    cout << st.pop();
    cout << st.pop();

    return 0;
}