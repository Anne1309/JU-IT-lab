#include <stdio.h>
#include <stdlib.h>

// Function to print the array after each pass
void printArray(int arr[], int n, int pass) {
    printf("After pass %d: ", pass);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    int pass = 1;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        printArray(arr, n, pass++);
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    int pass = 1;
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        // Swap the found minimum element with the first element
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
        printArray(arr, n, pass++);
    }
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    int pass = 1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        printArray(arr, n, pass++);
    }
}

// Partition function used in Quick Sort
int partition(int arr[], int low, int high, int* pass, int n) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap arr[i + 1] and arr[high] (or pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    printArray(arr, n, (*pass)++);
    return (i + 1);
}

// Quick Sort function
void quickSort(int arr[], int low, int high, int* pass, int n) {
    if (low < high) {
        int pi = partition(arr, low, high, pass, n);
        quickSort(arr, low, pi - 1, pass, n);
        quickSort(arr, pi + 1, high, pass, n);
    }
}

// Merge function used in Merge Sort
void merge(int arr[], int l, int m, int r, int* pass, int n) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    printArray(arr, n, (*pass)++);
}

// Merge Sort function
void mergeSort(int arr[], int l, int r, int* pass, int n) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, pass, n);
        mergeSort(arr, m + 1, r, pass, n);
        merge(arr, l, m, r, pass, n);
    }
}

// Heapify function used in Heap Sort
void heapify(int arr[], int n, int i, int* pass) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest, pass);
    }
}

// Heap Sort function
void heapSort(int arr[], int n) {
    int pass = 1;
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, &pass);
    }

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        printArray(arr, n, pass++);
        heapify(arr, i, 0, &pass);
    }
}

// Main menu-driven program
int main() {
    int choice, n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n], original[n];

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        original[i] = arr[i];  // Save original array for resetting
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insertion Sort\n");
        printf("2. Selection Sort\n");
        printf("3. Bubble Sort\n");
        printf("4. Quick Sort\n");
        printf("5. Merge Sort\n");
        printf("6. Heap Sort\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        for (i = 0; i < n; i++) {
            arr[i] = original[i];  // Reset array to original
        }

        switch (choice) {
            case 1:
                printf("Insertion Sort:\n");
                insertionSort(arr, n);
                break;

            case 2:
                printf("Selection Sort:\n");
                selectionSort(arr, n);
                break;

            case 3:
                printf("Bubble Sort:\n");
                bubbleSort(arr, n);
                break;

            case 4: {
                printf("Quick Sort:\n");
                int pass = 1;
                quickSort(arr, 0, n - 1, &pass, n);
                break;
            }

            case 5: {
                printf("Merge Sort:\n");
                int pass = 1;
                mergeSort(arr, 0, n - 1, &pass, n);
                break;
            }

            case 6:
                printf("Heap Sort:\n");
                heapSort(arr, n);
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
