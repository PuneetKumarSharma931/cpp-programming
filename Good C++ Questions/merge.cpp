#include <iostream>

using namespace std;

void merge(int arr[], int low, int mid, int high) {

    int *temp = new int[high + 1];
    int i = low;
    int j = mid+1;
    int k = low;

    while(i<=mid && j<=high) {

        if(arr[i]<arr[j]) {

            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }

    while(i<=mid)
        temp[k++] = arr[i++];

    while(j<=high) 
        temp[k++] = arr[j++];

    for(int l=low; l<=high; l++)
        arr[l] = temp[l];
}

void mergeSort(int arr[], int low, int high) {

    if(low<high) {

        int mid = low + (high-low)/2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int main() {

    int arr[] = {39, 42, 98, 22, 11, 13};

    mergeSort(arr, 0, 6);

    for(int i=0;i<6;i++)
        cout<<arr[i]<<" ";


    return 0;
}