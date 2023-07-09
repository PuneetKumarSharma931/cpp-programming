
#include<iostream>

using namespace std;

int MaxProfit(int arr[], int n) {

    int Min1 = INT_MAX;
    int Max1 = INT_MIN;
    int Min2 = INT_MAX;
    int Max2 = INT_MIN;
    int sum = 0;
    bool flag = false;
    int profit1 = 0;
    int profit2 = 0;

    for(int i=0;i<n;i++) {

        if(i==0 && n>=2) {

            if(arr[i]<arr[i+1]) {

                Min1 = min(Min1, arr[i]);
                continue;
            }
        }

        if(i!=0 && i<n-1 && !flag) {

            if(arr[i]<arr[i-1] && arr[i]<arr[i+1])
                Min1 = min(Min1, arr[i]);
        }

        if(i!=0 && i<n-1 && !flag && Min1!=INT_MAX) {

            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]) {

                Max1 = max(Max1, arr[i]);
                flag = true;
            }
        }

        if(i==n-1 && !flag && Min1!=INT_MAX) {

            if(arr[i]>arr[i-1])
                Max1 = max(Max1, arr[i]);
                break;
        }

        if(flag && i<n-1) {

            if(arr[i]<arr[i-1] && arr[i]<arr[i+1])
                Min2 = min(Min2, arr[i]);
        }

        if(flag && i<n-1 && Min2!=INT_MAX) {

            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
                Max2 = max(Max2, arr[i]);
        }

        if(flag && i==n-1 && Min2!=INT_MAX) {

            if(arr[i]>arr[i-1])
                Max2 = max(Max2, arr[i]);
        }

    }

    if(Min1!=INT_MAX && Max1!=INT_MIN)
        profit1 = Max1 - Min1;

    if(Min2!=INT_MAX && Max2!=INT_MIN)
        profit2 = Max2 - Min2;

        cout<<Min1<<" "<<Max1<<endl;
        cout<<Min2<<" "<<Max2<<endl;

    sum = profit1 + profit2;

    return sum;
}

int main() {

    int arr[] = {90, 80, 70, 60, 50};
    int n = 5;

    int max_profit = MaxProfit(arr, n);

    cout<<max_profit;

    return 0;
}