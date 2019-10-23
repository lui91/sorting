#include <iostream>
#include "HashTable.h"
#include <bitset>

int main() {
	ht::ht ht1(5, 1);
	ht1.add("Mario");
	std::string words[5] = { "Mario","Jorge", "Luisa", "Abdul" ,"Marta" };
	return 0;
}