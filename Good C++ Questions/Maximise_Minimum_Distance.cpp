
#include<iostream>
#include<algorithm>

using namespace std;

bool isFeasible(int mid, int arr[], int n, int k) {

    int element = 1;
    int ele = arr[0];

    for(int i=1;i<n;i++) {

        if((arr[i]-ele)>=mid) {

            element++;
            ele = arr[i];
        }
            
        if(element>=k)
            return true;
    }

    return false;
}

int maxDistance(int arr[], int n, int k) {

    sort(arr, arr+n);

    if(n<k)
        return -1;
        
    int ans = -1;
    int left = 1;
    int right = arr[n-1];
    int mid;

    while(left<right) {

        mid = (left+right)/2;

        if(isFeasible(mid, arr, n, k)) {

            ans = max(ans, mid);
            left = mid+1;
        }
        else {

            right = mid-1;
        }

    }

    return ans;
}

bool isPossible(int arr[], int n, int m, int mid) {

    int studentCount = 1, sum = 0;

    for(int i=0;i<n;i++) {

        sum+=arr[i];

        if(sum>mid) {

            studentCount++;
            sum = arr[i];
        }

        if(studentCount>m)
            return false;
    }

    return true;
}

int minimumPageAllocation(int arr[], int n, int m) {

    if(n<m)
        return -1;

    sort(arr, arr+n);

    int left = 0, right = 0, mid,result = -1;

    for(int i=0;i<n;i++)
        right+=arr[i];

    while(left<=right) {

        mid = (left+right)/2;

        if(isPossible(arr, n, m, mid)) {

            result = mid;
            right = mid-1;
        }
        else {

            left = mid+1;
        }
    }

    return result;

}

//Painter's Partition Problem

bool canPaint(int arr[], int n, int m, int mid) {

    int painterCount = 1;
    int area = 0;

    for(int i=0;i<n;i++) {

        area+=arr[i];

        if(area>mid) {

            painterCount++;
            area = arr[i];
        }

        if(painterCount>m)
            return false;
    }

    return true;

}

int minimumTime(int arr[], int n, int m) {

    if(n<m)
        return -1;

    int left = 0, right = 0, mid, ans = 0;

    sort(arr, arr+n);

    for(int i=0;i<n;i++)
        right+=arr[i];

    while(left<=right) {

        mid = left + (right - left)/2;

        if(canPaint(arr, n, m, mid)) {

            ans = mid;
            right = mid-1;
        }
        else {

            left = mid+1;
        }
    }

    return ans;
}

//Search in a sorted and rotated array

int binarySearch(int arr[], int left, int right, int ele) {

    int mid;

    while(left<=right) {

        mid = left + (right - left)/2;

        if(arr[mid]==ele) {

            return mid;
        }
        else if(arr[mid]>ele) {

            left = mid+1;
        }
        else {

            right = mid-1;
        }
    }

    return -1;
}

int rotatedArraySearch(int arr[], int n, int ele) {

    int pivot;
    int left, right;
    int index;

    for(int i=0;i<n-1;i++) {

        if(arr[i]>arr[i+1]) {

            pivot = i;
            break;
        }
    }

    left = 0;
    right = pivot;

    if((index = binarySearch(arr, left, right, ele))!=-1) {

        return index;
    }
    else {

        return binarySearch(arr, pivot+1, n-1, ele);
    }

    return -1;
}

//Optimised Code for Rotated Array

int searchInRotatedArray(int arr[], int n, int left, int right, int ele) {

    if(left>right)
        return -1;

    int mid = left + (right-left)/2;

    if(arr[mid]==ele)
        return mid;

    if(arr[left]<arr[mid]) {

        if(arr[left]<ele && arr[mid]>ele) {

            return searchInRotatedArray(arr, n, left, mid-1, ele);
        }
        else {

            return searchInRotatedArray(arr, n, mid+1, right, ele);
        }
    }
    else {

        return searchInRotatedArray(arr, n, mid+1, right, ele);
    }

    return -1;

}

int findPeak(int arr[], int n) {

    if(n==1)
        return arr[0];

    int peak = -999999;

    for(int i=0;i<n;i++) {

        if(i==0) {

            if(arr[i]>arr[i+1]) {

                if(peak<arr[i])
                    peak = arr[i];
            }
        }

        if(i==n-1) {

            if(arr[i]>arr[i-1]) {

                if(peak<arr[i])
                    peak = arr[i];
            }
        }

        if(i!=0 && i!=(n-1)) {

            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]) {

                if(peak<arr[i])
                    peak = arr[i];
            }
        }
    }

    return peak;
}

int main() {

    system("clear");

    int arr[] = {10, 20, 15, 2, 23, 90, 67};
    
    cout<<"\nThe Peak element is: "<<findPeak(arr, 7);
    
    return 0;
}