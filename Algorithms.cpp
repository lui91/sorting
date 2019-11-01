#include <iostream>
#include "HashTable.h"
#include <bitset>

int main() {
	ht::ht ht1(5, 2);
	string words [5]= { "Mario","Jorge", "Luisa", "Mario" ,"Marta" };
	for (size_t i = 0; i < 5; i++)
    {
        ht1.add(words[i]);
    }
	return 0;
}