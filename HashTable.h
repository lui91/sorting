#include <string>
#include <bitset>
#include "linked_list.cpp"

namespace ht {
	class ht {
	public:

		ht(int size, int hashing_method) {
			this->hashing_method = hashing_method;
			if (hashing_method == 1)
			{
				generate_matrix();
			}
			
		}

		static const int table_size = 50;
		int hashing_method;
		static const int hash_size=128;
		static const int u_size = ht::hash_size;
		static const int b_size = 64;
		std::bitset<ht::hash_size> random_matrix[b_size][u_size];
		linked_list listas[ht::table_size];

		void add(std::string id);
		int universal(std::string id);
		int dot_product(std::bitset<ht::hash_size> row, std::bitset<ht::hash_size> bits);
		void sum(std::bitset<ht::hash_size> row, std::bitset<ht::hash_size> bits);
		void subtraction(std::bitset<ht::hash_size> row, std::bitset<ht::hash_size> bits);
		long long Binary(int num);
		int decimal(long long num);
		int division(std::string id);
		int multiplication(std::string id);
		std::bitset<ht::hash_size> str_to_bits(std::string word);
		std::string TextToBinaryString(std::string words);
		
		
	private:
		void generate_matrix();
		
	};

	
}