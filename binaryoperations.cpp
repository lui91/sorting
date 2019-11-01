#include <bitset>
#include <iostream>

using namespace std;

class binaryoperations
{
private:
    /* data */
public:
    static const int hash_size = 128;

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

    template<unsigned int N>
    void bitsetSubtract(std::bitset<hash_size>& x, const std::bitset<hash_size>& y)
    {
        bool borrow = false;
        for (int i = 0; i < N; i++)
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

    std::bitset<hash_size> extracted_bits(std::bitset<hash_size> num){
        int mid = hash_size /2;
        int bits2extract = 7;
        std::bitset<hash_size> idx;
        cout << num.to_string() << endl << "extracted: ";
        for (size_t i = mid; i < mid+bits2extract; i++)
        {
            idx.set(i, num[i]);
            cout << num[i];
        }
        cout << endl;
        cout << idx.to_string() << endl;
        return idx;
    }
};

