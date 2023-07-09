
#include<iostream>

using namespace std;

int main() {

    int arr[5] = {1, 3, 2, 5, 8};

    int temp;

    for(int i=0;i<5;i+=2) {

        if(i+1 < 5) {

        temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;

        }

    }

    for(int i=0;i<5;i++) {

        cout<<arr[i]<<" ";
    }

    return 0;
}