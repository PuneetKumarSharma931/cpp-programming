
#include<iostream>

using namespace std;

int medianOfArray(int arr1[], int arr2[], int n) {

    int i = 0;
    int j = 0;
    int count = 0;
    int elementsBeforeMedian = n;
    int median1 = -1;
    int median2 = -1;

    median2 = arr1[i]<arr2[j]?arr1[i]:arr2[j];

    while(i<n && j<n) {

        if(arr1[i]<=arr2[j]) {

            count++;
            median1 = median2;
            i++;
            median2 = arr1[i];
        }
        else {

            count++;
            median1 = median2;
            j++;
            median2 = arr2[j];
        }

        if(count==elementsBeforeMedian)
            break;
    }

    cout<<median1<<" "<<median2;

    return (median1 + median2)/2;
}

int main() {

    system("clear");

    int arr1[] = {1, 2, 3, 6};
    int arr2[] = {4, 6, 8, 10};
    int n = 4;

    cout<<"Median is "<<medianOfArray(arr1, arr2, n);

    return 0;
}