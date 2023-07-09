
#include<iostream>
#include<vector>

using namespace std;

int main() {

    system("clear");
    
    int n;
    int k;

    cin>>n;
    cin>>k;

    vector<int> arr(n);

    for(int i=0;i<n;i++) {

        cin>>arr[i];
    }

    int i=0,ans = 0, zeroCount = 0;

    for(int j=0;j<n;j++) {

        if(arr[j]==0)
        zeroCount++;

        while(zeroCount>k) {

            if(arr[i]==0)
            zeroCount--;

            i++;
        }

        ans = max(ans, j-i+1);
    }

    cout<<endl<<ans<<" ";

    return 0;
}