#include <iostream>
#include "HashTable.h"
#include <bitset>

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
	return 0;
}