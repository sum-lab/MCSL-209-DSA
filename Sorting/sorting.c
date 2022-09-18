#include <stdio.h>

void swap(int *i, int*j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

void printArray(int A[], int n) {
    printf("\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t", A[i]);
    }
}

void bubblesort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n-i; j++) {
            if (A[j-1] > A[j]) {
                swap(&A[j-1], &A[j]);
            }
        }
    }
}

void quicksort(int A[], int low, int high) {
    if (low < high) {
        int mid = partition(A, low, high);
        quicksort(A, low, mid);
        quicksort(A, mid+1, high);
    }

}

int partition(int A[], int low, int high) {
    int pivot = A[low];
    int i = low;
    int j = high;
    while (i < j) {
        while(A[i] <= pivot) {
            i++;
        } 
        while (A[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[j], &A[low]);
    return j;
}

void merge(int A[], int low, int mid, int high) {
    int i, j;
    i = low;
    j = mid+1;
    int n = 0;
    int sorted[high-low+1];
    while(i <= mid && j <= high) {
        if(A[i] <= A[j]){
            sorted[n] = A[i];
            i++;
        } else {
            sorted[n] = A[j];
            j++;
        }
        n++;
    }
    while (i <= mid) {
        sorted[n++] = A[i++];
    }
    while (j <= high) {
        sorted[n++] = A[j++];
    }
    for(int i = 0; i < n; i++) {
        A[low+i] = sorted[i];
    }
    
}

void mergesort(int A[], int low, int high) {
    if (low < high) {
        int mid = (low+high)/2;
        mergesort(A, low, mid);
        mergesort(A, mid+1, high);
        merge(A, low, mid, high);
    }
}

void insertionSort(int A[], int n) {
    for(int i = 1; i < n; i++) {
        int j = i-1;
        int current = A[i];
        // shift to right
        while (j >= 0 && A[j] > current) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = current;
    }
}

int binarySearch(int A[], int low, int high, int key) {
    if (low <= high) {
        int mid = (low+high)/2;
        if (key == A[mid]) {
            return mid;
        }
        else if (key < A[mid]){
            return binarySearch(A, low, mid, key);
        } else if (key > A[mid]) {
            return binarySearch(A, mid+1, high, key);
        }
    }
    return -1;
}

int main(){
    int array[] = {3, 10, 7, 1, 45, 0, 8, 2, 5, 4};
    int n = 10;
    bubblesort(array, n);
    printArray(array, n);

    int array2[] = {3, 10, 7, 1, 45, 0, 8, 2, 5, 4};
    insertionSort(array2, n);
    printArray(array2, n);
    printf("\n%d", binarySearch(array2, 0, n-1, 3));
}

