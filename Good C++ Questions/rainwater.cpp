
#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

int ranWater(int arr[], int n) {

    int ans = 0;
    stack<int> st;

    for(int i=0;i<n;i++) {

        while(!st.empty() && arr[st.top()]<arr[i]) {

            int curr = st.top();

            st.pop();

            if(st.empty()) {
                break;
            }

            int diff = i - st.top() - 1;

            ans+=(min(arr[st.top()], arr[i]) - arr[curr])*diff;
        }

        st.push(i);
    }

    return ans;
    
}

int main() {

    system("clear");

    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = 12;

    cout<<ranWater(arr, n);

    return 0;
}