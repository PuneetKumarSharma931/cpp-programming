
//Quick Sort Practice

#include <stdio.h>
#include <stdlib.h>

void traversal(int *arr, int n) {
    
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
}

int Partition(int *arr, int low, int high) {
    
    int temp;
    int pivot = arr[low];
    int i = low+1;
    int j = high;


    do{
    while(pivot>=arr[i]) {
        i++;
    }

    while(pivot<arr[j]) {
        j--;
    }

    if(i<=j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}while(i<=j);

temp = arr[low];
arr[low] = arr[j];
arr[j] = temp;

return j;

}

void quickSort(int *arr, int low, int high) {

    int partition;

    if(low<high) {

    partition = Partition(arr, low, high);

    quickSort(arr, 0, partition-1);
    quickSort(arr, partition+1, high);

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

    quickSort(arr, 0, n-1);

    printf("\nArray after Sorting\n");

    traversal(arr, n);

    free(arr);

    return 0;

}