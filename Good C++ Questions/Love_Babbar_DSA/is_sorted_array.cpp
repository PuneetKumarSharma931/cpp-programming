
#include<iostream>

using namespace std;

bool isSorted(int arr[], int i, int n) {

    if(i==n-1)
        return true;

    if(arr[i]>arr[i+1])
        return false;

    return isSorted(arr, i+1, n);
}

int main() {

    system("clear");

    int arr[6] = {2, 4, 6, 9, 13, 11};

    if(isSorted(arr, 0, 6)) {

        cout<<"The array is sorted!";
    }
    else {
        cout<<"The array is not sorted!";
    }
    
    return 0;
}