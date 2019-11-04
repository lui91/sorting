#include <bitset>
#include <iostream>
#include <cmath>

using namespace std;

class binaryoperations
{
private:
    /* data */
public:
    
    static const int hash_size = 128;
    static const int bits2extract = 7;

    bool fullAdder(bool b1, bool b2, bool& carry)
    {
        bool sum = (b1 ^ b2) ^ carry;
        carry = (b1 && b2) || (b1 && carry) || (b2 && carry);
        return sum;
    }

    bool fullSubtractor(bool b1, bool b2, bool& borrow)
    {
        bool diff;
        if (borrow)
        {
            diff = !(b1 ^ b2);
            borrow = !b1 || (b1 && b2);
        }
        else
        {
            diff = b1 ^ b2;
            borrow = !b1 && b2;
        }
        return diff;
    }

    void bitsetAdd(std::bitset<hash_size>& x, const std::bitset<hash_size>& y)
    {
        bool carry = false;
        for (int i = 0; i < hash_size; i++)
        {
            x[i] = fullAdder(x[i], y[i], carry);
        }
    }

    void bitsetSubtract(std::bitset<hash_size>& x, const std::bitset<hash_size>& y)
    {
        bool borrow = false;
        for (int i = 0; i < hash_size; i++)
        {
            if (borrow)
            {
                if (x[i])
                {
                    x[i] = y[i];
                    borrow = y[i];
                }
                else
                {
                    x[i] = !y[i];
                    borrow = true;
                }
                }
            else
            {
                if (x[i])
                {
                    x[i] = !y[i];
                    borrow = false;
                }
                else
                {
                    x[i] = y[i];
                    borrow = y[i];
                }
            }
        }
    }

    void bitsetMultiply(std::bitset<hash_size>& x, const std::bitset<hash_size>& y)
    {
        std::bitset<hash_size> tmp = x;
        x.reset( );
        // we want to minimize the number of times we shift and add
        if (tmp.count( ) < y.count( ))
        {
        for (int i=0; i < hash_size; i++)
            if (tmp[i]) bitsetAdd(x, y << i);
        }
        else
        {
        for (int i=0; i < hash_size; i++)
            if (y[i]) bitsetAdd(x, tmp << i);
        }
    }

    std::bitset<hash_size> str_to_bits(std::string word) {
        std::bitset<hash_size> b;
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

    int extracted_bits(std::bitset<hash_size> num){
        int mid = hash_size /2;
        string bits;
        string id = num.to_string();
        bits.append(id.begin()+ mid, id.begin()+ mid + bits2extract);
        std::bitset<bits2extract> bit_idx(bits);
        int val = bit_idx.to_ulong();
        return val;
    }
    
    std::string TextToBinaryString(std::string words) {
		std::string binaryString = "";
		for (char& _char : words) {
			binaryString +=std::bitset<8>(_char).to_string();
		}
		return binaryString;
	}

    long long to_binary(int num)
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

	int to_decimal(long long num)
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

};
