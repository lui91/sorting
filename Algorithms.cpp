#include <iostream>
#include "HashTable.h"
#include <bitset>
#include "heaps.cpp"

int main() {
	string id = "luis";
	cout << "adding: " << id << endl;
	ht::ht ht1(5, 1);
	ht1.add(id);

	ht::ht ht2(5, 3);
	ht2.add(id);
	ht2.add(id);
	string words [5]= { "Mario","Jorge", "Luisa", "Mario" ,"Marta" };
	for (size_t i = 0; i < 5; i++)
    {
        ht1.add(words[i]);
		ht2.add(words[i]);
    }

	ht2.listas[0].display();

	srand (2);
    init_vector();
    std::cout << "originales: ";
    for (size_t i = 1; i <= max_heap.N; i++) {
        std::cout  << max_heap.numbers[i] << ' ';
    }

    std::cout << std::endl;
    build_max_heap(max_heap, max_heap.N);
    std::cout << std::endl;

    std::cout << "ordenados: ";
    for (size_t i = 1; i <= max_heap.N; i++) {
        std::cout << max_heap.numbers[i] << ' ';
    }

	return 0;
}