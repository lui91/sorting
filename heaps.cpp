#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

struct heap{
    static const int length = 8;
    int numbers[length] = {0};
    int N = length-1;
}max_heap;


void max_heapify(heap& work_heap, int i){
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = 0;

    if(left<= work_heap.N and work_heap.numbers[left] > work_heap.numbers[i] )
        largest = left;
    else
        largest = i;
    if(right <= work_heap.N and work_heap.numbers[right] > work_heap.numbers[largest] )
        largest = right;
    if(largest != i )
    {
        int buff = work_heap.numbers[i];
        work_heap.numbers[i] = work_heap.numbers[largest];
        work_heap.numbers[largest] = buff;
        std::cout << "swap: " << max_heap.numbers[i] << " for: " << max_heap.numbers[largest] << std::endl;
        for (size_t i = 1; i <= max_heap.N; i++) {
            std::cout  << max_heap.numbers[i] << ' ';
        }
        std::cout << std::endl;
        max_heapify (work_heap, largest);
    }
}

void build_max_heap(heap& work_heap, int N){
    std::cout << N << std::endl;

    for (int i = floor(N/2); i >= 1; i--) {
        max_heapify(work_heap, i);
    }
}

void init_vector(){
    for (int i = 1; i <= max_heap.N; ++i) {
        max_heap.numbers[i] = rand() % 100;
    }
}