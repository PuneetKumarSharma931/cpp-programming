
#include<iostream>

using namespace std;

void bubbleSort(int arr[], int i, int j, int n) {

    if(j==n-1) {

        j = 0;
        i++;
    }

    if(i==n-1) {

        return;
    }

    if(arr[j]>arr[j+1])
        swap(arr[j], arr[j+1]);

    bubbleSort(arr, i, j+1, n);
    
}

int main() {

    int arr[8] = {3, 14,20,10,11,8,33,2};

    bubbleSort(arr, 0, 0, 8);

    for(int i=0;i<8;i++)
        cout<<arr[i]<<" ";

    return 0;
}