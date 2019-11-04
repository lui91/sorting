#include "HashTable.h"
#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

namespace ht {
	void ht::add(std::string id) {
		if (ht::hashing_method == 1) {
			universal(id);
		}
		else if (ht::hashing_method == 2) {

			division(id);
		}
		else if (ht::hashing_method == 3) {
			multiplication(id);
		}
	}

	int ht::universal(std::string id) {
		cout << "universal:" << id << endl;
		
		bitset<ht::hash_size> w(bp.TextToBinaryString(id));
		// M must be power of 2
		
		string product;
		for (size_t i = 0; i < b_size; i++)
		{
			for (size_t j = 0; j < u_size; j++)
			{
				product.append(dot_product(ht::random_matrix[i][j], w));
			}
			
		}
		bitset<ht::hash_size> bits(product);
		cout << "product " << bits.to_ulong() << endl;
		
		return 0;
	}

	string ht::dot_product(bitset<ht::hash_size> row, bitset<ht::hash_size> bits)
	{
		bitset<ht::hash_size> i(row & bits);
		bitset<ht::hash_size> cinco("1010101010101010101010101010101");
		bitset<ht::hash_size> tres("110011001100110011001100110011");
		bitset<ht::hash_size> F("11110000111100001111000011110000");
		bitset<ht::hash_size> zero_uno("1000000010000000100000001");
		bitset<ht::hash_size> uno("1");
		i = (i >> 1) & cinco;
		i = i & tres;
		bp.bitsetAdd((i), (i >> 2)) ;
		i = i & tres;
		bp.bitsetAdd(i, (i>>4));
		i = i & F;
		bp.bitsetMultiply(i, zero_uno);
		i = i >> 24;
		i = i & i & uno;
		int idx = bp.to_decimal(i.to_ullong());
		std::stringstream ss;
		ss << idx;
		return ss.str();
	}

	int ht::division(std::string id) {
		string test = bp.TextToBinaryString(id);
		std::bitset<ht::hash_size> b(test);
		unsigned long long idx =  b.to_ullong() % ht::table_size;
		int status = ht::listas[idx].insert(id);
		if (status)
		{
			cout << "division hashing idx:  " << idx << endl;
		}else
		{
			cout << "That entry already exists" << endl;
		}
		
		return 0;
	}

	int ht::multiplication(std::string id) {
		std::bitset<ht::hash_size> b(bp.TextToBinaryString(id));
		std::bitset<ht::hash_size> m(hash_size);
		const float A =  0.5;
		bp.bitsetMultiply(b,m);
		int idx = bp.extracted_bits(b);
		int status = ht::listas[idx].insert(id);
		if (status)
		{
			cout << "multiplication hashing idx:  " << idx << endl;
		}else
		{
			cout << "That entry already exists" << endl;
		}
		return 0;
	}

	void ht::generate_matrix()
	{
		for (int i = 0; i < ht::b_size; ++i) {
			for (int j = 0; j < ht::u_size; ++j) {
				ht::random_matrix[i][j] = rand() % 2;
			}
		}
	}

}