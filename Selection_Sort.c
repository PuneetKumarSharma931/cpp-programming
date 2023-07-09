
//Selection Sort Practice

#include <stdio.h>
#include <stdlib.h>

void traversal(int *arr, int n) {
    
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
}

void selectionSort(int *arr, int n) {
    int temp;
    int minindex;

    for(int i=0;i<n-1;i++) {
        minindex = i;

        for(int j=i+1;j<n;j++) {
            if(arr[j]<arr[minindex]) {
                minindex = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = temp;
    }
}

int main() {
    int n;

    system("clear");

    printf("\nHow many elements you want in your array?:");

    scanf("%d",&n);

    int *arr = (int *)malloc(n*sizeof(int));

    printf("\nInput %d elements\n",n);

    for(int i=0;i<n;i++) {
        printf("\nInput element %d:",i+1);
        scanf("%d",&arr[i]);
    }

    printf("\nArray before Sorting\n");

    traversal(arr, n);

    selectionSort(arr, n);

    printf("\nArray after Sorting\n");

    traversal(arr, n);

    free(arr);

    return 0;

}