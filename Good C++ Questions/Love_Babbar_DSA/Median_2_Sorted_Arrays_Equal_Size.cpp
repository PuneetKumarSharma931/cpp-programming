#include<iostream>

using namespace std;

float medianSortedEqual(int arr1[], int arr2[], int n) {

    int left1 = 0;
    int right1 = n-1;
    int mid1;
    int median1 = -1;
    int left2 = 0;
    int right2 = n-1;
    int mid2;
    int median2 = -1;

     mid1 = left1 + (right1 - left1)/2;
     mid2 = left2 + (right2 - left2)/2;

    while(left1<=right1 && left2<=right2) {

        if(median1!=-1 && median2!=-1)
            break;

        if(arr1[mid1]<arr2[mid2]) {

            if(mid2>0 && arr1[mid1]>arr2[mid2-1]) {

                median1 = mid1;
                median2 = mid2;
            }
            else {

                left1 = mid1+1;
                right2 = mid2-1;
                mid1 = left1 + (right1 - left1)/2;
                mid2 = left2 + (right2 - left2)/2;
            }
            
        }
        else {

           if(mid1>0 && arr2[mid2]>arr1[mid1-1]) {

            median2 = mid2;
            median1 = mid1;

           }
           else {

                left2 = mid2 + 1;
                right1 = mid1 - 1;
                mid2 = left2 + (right2 - left2)/2;
                mid1 = left1 + (right1 - left1)/2;
           }
        }

    }

    if(median1==-1 && median2==-1) {

        median1 = mid1;
        median2 = mid2;
    }

    return ((arr1[median1] + arr2[median2])/2);
}

int main() {

    system("clear");

    int arr1[] = {1, 2, 3, 6};
    int arr2[] = {4, 6, 8, 10};
    int n = 4;

    cout<<"Median is "<<medianSortedEqual(arr1, arr2, n);
    return 0;
}