
#include<iostream>

using namespace std;

bool linearSearch(int arr[], int n, int k) {

    if(n==0) {
        return false;
    }

    if(arr[0]==k) {

        return true;
    }
    else {

        return linearSearch(arr+1, n-1, k);
    }
}

int main() {

    int arr[5] = {1, 2, 3, 4, 5};

    system("clear");

    int found = linearSearch(arr, 5, 4);

    if(found) {

        cout<<"The element is found in the array";
    }
    else {

        cout<<"The element does not exist in the array!";
    }
    return 0;
}