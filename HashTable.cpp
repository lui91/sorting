// HashTable.cpp : Defines the functions for the static library.
//
#include "HashTable.h"
#include <iostream>
#include <cmath>
#include <numeric>
#include <vector>
#include <string>

using namespace std;

namespace ht {
	// extern Node *head;
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
		
		bitset<ht::hash_size> w(ht::str_to_bits(id));
		// M must be power of 2
		//TODO: repair 3 dimensions array
		cout << "bits size: " << w << endl;
		
		int product[ht::u_size];
		for (size_t i = 0; i < 1; i++)
		{
			for (size_t j = 0; j < 1; j++)
			{
				product[i] = dot_product(ht::random_matrix[i][j], w);
			}
			
		}

		return 0;
	}

	int ht::dot_product(bitset<ht::hash_size> row, bitset<ht::hash_size> bits)
	{
		bitset<ht::hash_size> i(row & bits);
		bitset<ht::hash_size> cinco(01010101);
		bitset<ht::hash_size> tres(00110011);
		long long tres_i = 01010101;
		long long tres_l = 00110011;
		long long cinco_l = 01010101;
		
		unsigned int tresi = tres_i & tres_i;
		cout << "tresi: " << tresi << endl;
		cout << "tres_l: " << tres_l << endl;
		long long tresl = tres_l + cinco_l;
		cout << "tresl: " << tresl << endl;

		cout << "row: " << row << endl;
		cout << "bits: " << bits << endl;
		ht::sum(row, bits);
		//ht::subtraction(row, bits);
		//i = i + ((i >> 1) & cinco);

		//int total = ht::random_matrix[row][0] & bits;


		return 0;
	}

	void ht::sum(bitset<ht::hash_size> row, std::bitset<ht::hash_size> bits)
	{
		std::bitset<ht::hash_size> const m("1");
		std::bitset<ht::hash_size> result;
		for (auto i = 0; i < result.size(); ++i) {
			std::bitset<ht::hash_size> const diff(((row >> i)& m).to_ullong() + ((bits >> i)& m).to_ullong() + (result >> i).to_ullong());
			result ^= (diff ^ (result >> i)) << i;
		}
		cout << "sum: " << result << endl;
	}

	void ht::subtraction(std::bitset<ht::hash_size> row, std::bitset<ht::hash_size> bits)
	{
		//int d_row = ht::decimal(row);


	}

	long long ht::Binary(int num)
	{
		int rem;
		long long binary = 0, i = 1;
		do
		{
			rem = num % 2;
			binary = binary + (i * rem);
			num = num / 2;
			i = i * 10;
		} while (num > 0);
		return binary;
	}

	int ht::decimal(long long num)
	{
		int rem, decimal = 0, i = 0;
		while (num > 0)
		{
			rem = num % 10;
			decimal = decimal + (rem * pow(2, i));
			i++;
			num /= 10;
		}
		return decimal;
	}

	int ht::division(std::string id) {
		cout << "division: " << id << endl;
		std::bitset<ht::hash_size> b(TextToBinaryString(id));
		int idx = b.to_ullong() % ht::table_size;
		cout << " " << idx << endl;
		int status = ht::listas[idx].insert(id);
		if (status)
		{
			cout << id << " added to de idx " << idx << endl;
		}else
		{
			cout << "That entry already exists" << endl;
		}
		return 0;
	}

	std::string ht::TextToBinaryString(std::string words) {
		std::string binaryString = "";
		for (char& _char : words) {
			binaryString +=std::bitset<8>(_char).to_string();
		}
		return binaryString;
	}

	int ht::multiplication(std::string id) {
		cout << "multiplication" << endl;
		return 0;
	}

	std::bitset<ht::hash_size> ht::str_to_bits(std::string word) {
		std::bitset<ht::hash_size> b;
		for (int i = 0; i < word.length(); ++i) {
			char c = word[i];
			for (int j = 7; j >= 0 && c; --j) {
				if (c & 0x1) {
					b.set(8 * i + j);
				}
				c >>= 1;
			}
		}
		return b;
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