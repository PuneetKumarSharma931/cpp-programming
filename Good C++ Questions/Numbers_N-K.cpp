
#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<int> Numbers_Appearing_N_K(int arr[], int n, int k) {

    map<int, int> m;
    int count = n/k;
    vector<int> ans;

    for(int i=0;i<n;i++)
        m[arr[i]]++;

    for(auto i: m) {

        if(i.second>count)
            ans.push_back(i.first);
    }

    return ans;
}

int main() {

    int arr[] = {1, 1, 2, 2, 3, 5, 4, 2, 2, 3, 1, 1, 1 };
    int n = 13;
    vector<int> ans;

    ans = Numbers_Appearing_N_K(arr, n, 4);

    for(int i=0;i<ans.size();i++) {

        cout<<ans[i]<<" ";
    }

    return 0;
}