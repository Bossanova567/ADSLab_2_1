#ifndef ADSLAB_2_1_HEAP_H
#define ADSLAB_2_1_HEAP_H

#include <iostream>
using namespace std;

void MaxHeapify(int* A, int i, int heap_size);
void BuildMaxHeap(int* A, int n);
void MinHeapify(int* A, int i, int heap_size);
void BuildMinHeap(int* A, int n);
void HeapSort(int* A, int n, int choice);
void Show(int* A, int n);


#endif //ADSLAB_2_1_HEAP_H
