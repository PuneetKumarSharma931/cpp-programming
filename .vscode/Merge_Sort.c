
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void printArray(int arr[], int n) {

    printf("\n");

    for(int i=0;i<n;i++) {

        printf("%d ",arr[i]);
    }
}

int Max(int arr[], int n) {

    int max = INT_MIN;

    for(int i=0;i<n;i++) {

        if(arr[i]>max) {

            max = arr[i];
        }
    }

    return max;
}

void countSort(int arr[], int n) {

    int max = Max(arr,n);

    int* count = (int *)malloc(sizeof(int)*(max+1));

    for(int i=0;i<=max;i++) {

        count[i] = 0;
    }

    for(int i=0;i<n;i++) {

        count[arr[i]] = count[arr[i]]+1;
    }

    int j=0;
    int i=0;

    while(i<=max) {

        if(count[i]>0) {

            arr[j] = i;
            count[i]--;
            j++;
        }
        else {
            i++;
        }
    }
}



int main() {

    system("clear");

    int arr[] = {8,9,14,4,1,2,2,18,25,15};

    int n = 10;

    printArray(arr,n);

    countSort(arr,n);

    printArray(arr,n);

    return 0;
}