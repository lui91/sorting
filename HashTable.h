#include <string>
#include <bitset>

namespace ht {
	class l_list{

    struct Node* head = NULL;

    public:

		struct Node { 
			std::string text; 
			struct Node *next; 
		}; 

        int search_node(std::string text);
        void insert(std::string new_data);
        void display();

	};

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
		l_list lists [table_size];

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