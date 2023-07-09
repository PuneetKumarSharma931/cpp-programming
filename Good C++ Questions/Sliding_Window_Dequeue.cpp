
#include<iostream>
#include<deque>
#include<vector>

using namespace std;

int main() {

    system("clear");
    
    int n;
    int k;

    cout<<"Input Data: ";
    cin>>n;
    cin>>k;

    vector<int> arr(n);

    for(int i=0;i<n;i++) {

        cin>>arr[i];
    }

    vector<int> ans;
    deque<int> q;

    for(int i=0;i<k;i++) {

        while(!q.empty() && arr[i]>q.back()) {

            q.pop_back();
        }
        q.push_back(i);
    }

    ans.push_back(arr[q.front()]);

    for(int i=k;i<n;i++) {

        if(q.front()==i-k) {
            q.pop_front();
        }

        while(!q.empty() && arr[i]>q.back()) {

            q.pop_back();
        }

        q.push_back(i);

        ans.push_back(arr[q.front()]);
    }

    for(int i=0;i<ans.size();i++) {

        cout<<ans[i]<<" ";
    }

    return 0;
}