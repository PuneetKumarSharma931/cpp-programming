
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

vector<int> previousSmaller(vector<int> arr) {

    vector<int> small;
    stack<int> st;

    for(int i=0;i<arr.size();i++) {

        while(!st.empty() && arr[st.top()]>=arr[i]) {

            st.pop();
        }
        if(st.empty()) {

            small.push_back(-1);
        }
        else{

            small.push_back(st.top());
        }

        st.push(i);
    }

    return small;
}

vector<int> nextSmaller(vector<int> arr) {

    stack<int> st;
    vector<int> small;
    int index = arr.size();

    for(int i=(arr.size()-1);i>=0;i--) {

        while(!st.empty() && arr[st.top()]>=arr[i]) {

            st.pop();
        }
        if(st.empty()) {

            small.push_back(index);
        }
        else {

            small.push_back(st.top());
        }
        st.push(i);
    }

   reverse(small.begin(), small.end());

    return small;
}

int maxArea(vector<int> arr) {

    vector<int> prevSmaller = previousSmaller(arr);
    vector<int> nxtSmaller = nextSmaller(arr);
    int maxArea = 0;
    int currentArea = 0;

    for(int i=0;i<arr.size();i++) {

        currentArea = (nxtSmaller[i] - prevSmaller[i]-1)*arr[i];

        maxArea = max(maxArea, currentArea);
    }

    return maxArea;

}

int main() {

    system("clear");

    vector<int> arr;

    int n;
    int element;

    cin>>n;

    for(int i=0;i<n;i++) {

        cin>>element;
        arr.push_back(element);
    }

    cout<<endl;

    cout<<"Max Size rectangle is: "<<maxArea(arr);

    return 0;
}