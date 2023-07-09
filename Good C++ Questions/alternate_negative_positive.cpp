
#include<iostream>

using namespace std;

void rearrange(int arr[], int start, int end) {

    int temp = arr[end];

    while(end>start) {

        arr[end] = arr[end-1];
        end--;
    }

    arr[start] = temp;
}

void alternate(int arr[], int n) {

    int i = 0;
    int j = 0;
    int k = 0;

    while(i<n && j<n && k<n) {

        //Checking for even index

        if(k%2==0) {

            //Checking if positive number is present

            if(arr[k]>=0) {
                
                i = k;
                j = k;

                while(i<n && arr[i]>=0) i++;

                if(i>=n)
                    break;

                //Rearranging elements

                rearrange(arr, j, i);
            }
        }
        else {

            //Checking if negative number is present

            if(arr[k]<0) {

                i = k;
                j = k;

                while(j<n && arr[j]<0) j++;

                if(j>=n)
                    break;

                //Rearranging elements

                rearrange(arr, i, j);
            }
        }

        k++;
    }
}

int main() {

    system("clear");

    int arr[10] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};

    alternate(arr, 10);

    for(int i=0;i<10;i++)
        cout<<" "<<arr[i];

    return 0;
}