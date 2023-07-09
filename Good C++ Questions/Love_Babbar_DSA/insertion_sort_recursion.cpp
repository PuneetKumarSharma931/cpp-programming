
#include<iostream>

using namespace std;

void insertionSort(int arr[], int n) {

    if(n==0 || n==1) {

        return;
    }

    insertionSort(arr, n-1);

    int ele = arr[n-1];
    int j = n-2;

    while(j>=0 && arr[j]>ele) {

        arr[j+1] = arr[j];
        j--;
    }

    arr[j+1] = ele;

}

int main() {

    system("clear");

    int arr[8] = {2, 8, 99, 11, 17, 15, 22, 20};

    insertionSort(arr, 8);

    for(int i=0;i<8;i++) 
        cout<<arr[i]<<" ";

    
    return 0;
}