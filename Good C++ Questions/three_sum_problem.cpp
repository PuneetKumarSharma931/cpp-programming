
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {

    system("clear");

    int n;
    int target;
    bool found = false;
    
    cin>>n;
    cin>>target;

    vector<int> arr(n);

    for(int i=0;i<n;i++) {

        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());

    for(int i=0;i<n;i++) {

        int low = i+1, high = n-1, curSum = 0;

        while(low<high) {

            curSum = arr[i] + arr[low] + arr[high];

            if(curSum==target) {
                found = true;
                break;
            }
            else if(curSum<target) {

                low++;
            }
            else {
                high--;
            }
        }
    }

    if(found) {
        cout<<"\nTrue"<<endl;
    }
    else {
        cout<<"False"<<endl;
    }

    return 0;
}