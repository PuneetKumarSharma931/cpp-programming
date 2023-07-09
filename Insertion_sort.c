
//Insertion Sort Practice

#include <stdio.h>
#include <stdlib.h>

void traversal(int *arr, int n) {
    
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
}

void insertionSort(int *arr, int n) {
    int j=0;
    int key;

    for(int i=1; i<n; i++) {

        key = arr[i];
        j = i-1;

        while(j>=0 && key<arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
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

    insertionSort(arr, n);

    printf("\nArray after Sorting\n");

    traversal(arr, n);

    free(arr);

    return 0;

}