
//Bubble Sort Practice

#include <stdio.h>
#include <stdlib.h>

void traversal(int *arr, int n) {
    
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
}

void bubbleSort(int *arr, int n) {

    int sorted = 0;
    int temp;

    for(int i=0;i<n-1;i++) {
        sorted = 1;

        for(int j=0;j<n-1-i;j++) {
            if(arr[j]>arr[j+1]) {

                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                sorted = 0;
            }
        }

        if(sorted)
        return;
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

    bubbleSort(arr, n);

    printf("\nArray after Sorting\n");

    traversal(arr, n);

    free(arr);

    return 0;

}