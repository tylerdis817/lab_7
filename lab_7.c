#include <stdio.h>

//intialize functions
void bubbleSort(int arr[], int n, int *totalSwaps);
void selectionSort(int arr[], int n, int *totalSwaps);
void printArray(int arr[], int size);

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int totalSwapsBubble1 = 0, totalSwapsSelection1 = 0;

    printf("Original Array1: ");
    printArray(array1, n1);
    bubbleSort(array1, n1, &totalSwapsBubble1);
    printf("Sorted with Bubble Sort: ");
    printArray(array1, n1);
    printf("Bubble Sort Total Swaps for Array1: %d\n", totalSwapsBubble1);

    //Resetting array1 to its original state
    int array1Original[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    printf("Original Array1 for Selection Sort: ");
    printArray(array1Original, n1);
    selectionSort(array1Original, n1, &totalSwapsSelection1);
    printf("Sorted with Selection Sort: ");
    printArray(array1Original, n1);
    printf("Selection Sort Total Swaps for Array1: %d\n\n", totalSwapsSelection1);

    //For array2
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n2 = sizeof(array2) / sizeof(array2[0]);
    int totalSwapsBubble2 = 0, totalSwapsSelection2 = 0;

    printf("Original Array2: ");
    printArray(array2, n2);
    bubbleSort(array2, n2, &totalSwapsBubble2);
    printf("Sorted with Bubble Sort: ");
    printArray(array2, n2);
    printf("Bubble Sort Total Swaps for Array2: %d\n", totalSwapsBubble2);

    //Resetting array2 to its original state
    int array2Original[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    printf("Original Array2 for Selection Sort: ");
    printArray(array2Original, n2);
    selectionSort(array2Original, n2, &totalSwapsSelection2);
    printf("Sorted with Selection Sort: ");
    printArray(array2Original, n2);
    printf("Selection Sort Total Swaps for Array2: %d\n", totalSwapsSelection2);

    return 0;
}

void bubbleSort(int arr[], int n, int *totalSwaps) {
    int i, j, temp;
    *totalSwaps = 0;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                (*totalSwaps)++;
            }
        }
    }
}

void selectionSort(int arr[], int n, int *totalSwaps) {
    int i, j, min_idx, temp;
    *totalSwaps = 0;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            (*totalSwaps)++;
        }
    }
}

//print function
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
