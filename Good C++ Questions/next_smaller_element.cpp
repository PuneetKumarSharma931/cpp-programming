
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

    system("clear");

    int n;

    cin>>n;

    vector<int> arr(n);

    for(int i=0;i<n;i++) {

        cin>>arr[i];
    }

    vector<int> ans;

    stack<int> st;

    for(int i=0;i<n;i++) {

        while(!st.empty() && st.top()>=arr[i]) {

            st.pop();
        }
        if(st.empty()) {

            ans.push_back(-1);
        }
        else {
            ans.push_back(st.top());
        }
        st.push(arr[i]);
    }

    cout<<endl;

    for(int i=0;i<ans.size();i++) {

        cout<<ans[i]<<" ";
    }

    return 0;
}