
#include<iostream>

using namespace std;

void selectionSort(int arr[], int n) {

    if(n==0 || n==1) {

        return;
    }

    int pos = 0;

    for(int i=0;i<n;i++) {

        if(arr[pos]<=arr[i]) {

            pos = i;
        }
    }

    swap(arr[pos], arr[n-1]);

    selectionSort(arr, n-1);
}

int main() {

    system("clear");

    int arr[8] = {2, 8, 13, 11, 17, 15, 22, 20};

    selectionSort(arr, 8);

    for(int i=0;i<8;i++) 
        cout<<arr[i]<<" ";

    return 0;
}