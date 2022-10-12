#include "Heap.h"

// i - індекс елементу піраміди

int Parent(int i){
    return floor(i/2);
}

int Left(int i){
    return 2*i;
}

int Right(int i){
    return 2*i+1;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void MaxHeapify(int* A, int i, int heap_size){
    int l = Left(i);
    int r = Right(i);
    int largest;
    if (l < heap_size && A[l] > A[i])
        largest = l;
    else
        largest = i;
    if (r < heap_size && A[r] > A[largest])
        largest = r;
    if (largest != i){
        swap(A[i], A[largest]);
        MaxHeapify(A, largest, heap_size);
    }
}

void BuildMaxHeap(int* A, int n){
    for (int i = n/2-1; i >= 0; i--){
        MaxHeapify(A, i, n);
    }
}

void MinHeapify(int* A, int i, int heap_size){
    int l = Left(i);
    int r = Right(i);
    int smallest;
    if (l < heap_size && A[l] < A[i])
        smallest = l;
    else
        smallest = i;
    if (r < heap_size && A[r] < A[smallest])
        smallest = r;
    if (smallest != i){
        swap(A[i], A[smallest]);
        MinHeapify(A, smallest, heap_size);
    }
}

void BuildMinHeap(int* A, int n){
    for (int i = n/2-1; i >= 0; i--){
        MinHeapify(A, i, n);
    }
}

void HeapSort(int* A, int n, int choice){
    if (choice == 1) {
        BuildMaxHeap(A, n);
        for (int i = n - 1; i > 0; i--) {
            swap(A[0], A[i]);
            MaxHeapify(A, 0, i);
        }
    }
    if (choice == 2){
        BuildMinHeap(A, n);
        for (int i = n - 1; i > 0; i--) {
            swap(A[0], A[i]);
            MinHeapify(A, 0, i);
        }
    }
}

void Show(int* A, int n){
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

