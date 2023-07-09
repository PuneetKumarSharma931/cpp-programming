
#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> stockSpan(int arr[], int n) {

    vector<int> ans;

    stack<pair<int,int> > st;

    for(int i=0;i<n;i++) {

        int day = 1;

        while(!st.empty() && st.top().first <= arr[i]) {

            day+=st.top().second;
            st.pop();
        }

        st.push(make_pair(arr[i], day));
        ans.push_back(day);
    }

    return ans;

}

int main() {

    system("clear");
    
    int arr[] = {100, 80, 60, 70, 60, 75, 85};

    vector<int> span = stockSpan(arr, 7);

    for(int i=0;i<span.size();i++) {

        cout<<span[i]<<" ";
    } 

    return 0;
}