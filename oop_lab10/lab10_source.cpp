#include <iostream>
#include <algorithm>
#include "lab10_header.h"
#include <queue>
#include <list>
#include <map>
using namespace std;

template<size_t bit_count>
bit_array<bit_count>::bit_array() : bit_arr_size(ceil(static_cast<double>(bit_count) / 8.)) {
	bit_arr.resize(bit_arr_size);
}

template<size_t bit_count>
bit_array<bit_count>::bit_array(const bit_array<bit_count>& other) : bit_arr_size(other.bit_arr_size) {
	bit_arr.resize(bit_arr_size);

	copy(other.bit_arr, other.bit_arr + bit_arr.size(), bit_arr);
}

template<size_t bit_count>
multimap<char, int> bit_array<bit_count>::multimap_set_keys(vector<char> keys) {
	multimap<char, int> mmap;
	int* bit_arr = dec_to_bin();
	for (int i = 0; i < bit_count; i++) {
		mmap.emplace(keys[i], bit_arr[i]);
	}

	return mmap;
}

template<size_t bit_count>
auto bit_array<bit_count>::multimap_get(char key, multimap<char, int> mmap) {
	auto is_in = mmap.find(key);

	if (is_in == mmap.end()) {
		return -1;
	}
	auto bit_val_by_key = mmap.find(key)->second;

	return bit_val_by_key;
}

template<size_t bit_count>
auto bit_array<bit_count>::multimap_delete(char key, multimap<char, int> mmap) {
	int count = mmap.erase(key);
	if (count == 0) {
		cerr << "Nothing has been deleted" << endl;
	}
	return mmap;
}

template<size_t bit_count>
auto bit_array<bit_count>::multimap_insert(char key, int val, multimap<char, int> mmap) {
	mmap.emplace(key, val);
	return mmap;
}


template<size_t bit_count>
unordered_multiset<int> bit_array<bit_count>::un_multiset_set_keys(vector<int> keys) {
	unordered_multiset<int> mmap;

	for (int i = 0; i < bit_count; i++) {
		mmap.emplace(keys[i]);
	}

	return mmap;
}

template<size_t bit_count>
void bit_array<bit_count>::un_multiset_cout(unordered_multiset<int> mmap) {
	if (mmap.empty()) {
		cout << "There is nothing to print." << endl;
		return;
	}
	unordered_multiset<int>::const_iterator iter;
	iter = mmap.begin();

	while (iter != mmap.end()) {
		cout << *iter << " ";
		iter++;
	}
}

template<size_t bit_count>
auto bit_array<bit_count>::un_multiset_get(int key, unordered_multiset<int> mmap) {
	auto is_in = mmap.find(key);

	if (is_in == mmap.end()) {
		return -1;
	}
	auto bit_val_by_key = mmap.find(key);

	return *bit_val_by_key;
}

template<size_t bit_count>
void bit_array<bit_count>::multimap_cout(multimap<char,int> mmap) {
	if (mmap.empty()) {
		cout << "There is nothing to print." << endl;
		return;
	}

	multimap<char, int>::const_iterator it;

	it = mmap.begin();
	while (it != mmap.end()) {
		cout << it->first << " - " << it->second << endl;
		it++;
	}

	return;
}

template<size_t bit_count>
auto bit_array<bit_count>::un_multiset_delete(int key, unordered_multiset<int> mmap) {
	int count = mmap.erase(key);
	if (count == 0) {
		cerr << "Nothing has been deleted" << endl;
	}
	return mmap;
}

template<size_t bit_count>
auto bit_array<bit_count>::un_multiset_insert(int key, unordered_multiset< int> mmap) {
	mmap.emplace(key);
	return mmap;
}


template<size_t bit_count>
bit_array<bit_count>::bit_array(bit_array<bit_count>&& other) : bit_arr(other.bit_arr) {
	other.bit_arr.resize(0);
}

template<size_t bit_count>
bit_array<bit_count>::~bit_array() {
	bit_arr_size = 0;
	bit_arr.resize(0);
}

template<size_t bit_count>
void bit_array<bit_count>::set_this_bit(unsigned int index, int value_1or0) {
	int* bit_arr = dec_to_bin();
	while (index >= this->bit_arr.size() * 8 or index < 0) {
		cerr << "Oops! Incorrect index! Please try again: ";
		cin >> index;
	}
	while (value_1or0 > 1 or value_1or0 < 0) {
		cerr << "Oops! Incorrect value! Please try 1 or 0: ";
		cin >> value_1or0;
	}

	bit_arr[index] = value_1or0;
	bin_to_dec(bit_arr);
}

template<size_t bit_count>
int bit_array<bit_count>::how_much(int value_1or0) {
	int* bit_arr = dec_to_bin();

	return count(bit_arr, bit_arr + this->bit_arr.size() * 8, value_1or0);
}

template<size_t bit_count>
bit_array<bit_count> bit_array<bit_count>::operator|(bit_array<bit_count>& bit1) {
	unsigned int min_size = min(bit1.get_size(), this->bit_arr_size);

	int* bit_1_arr = bit1.dec_to_bin();
	int* bit_2_arr = this->dec_to_bin();
	int* res_bit_arr = new int[min_size * 8];
	bit_array<bit_count> res_bit;

	transform(bit_1_arr, bit_1_arr + min_size * 8, bit_2_arr, res_bit_arr, [](int a, int b) {return (a or b); });
	res_bit.bin_to_dec(res_bit_arr);

	return res_bit;
}

template<size_t bit_count>
istream& operator>>(std::istream& in, bit_array<bit_count>& bit) {

	for (int i = 0; i < bit_count; i++) {
		int bit_val;
		in >> bit_val;
		while (bit_val != 0 and bit_val != 1) {
			cerr << "Oops! Incorrect value! Please try 1 or 0: ";
			in >> bit_val;
		}
		bit.set_this_bit(i, bit_val);
	}
	return in;
}

template<size_t bit_count>
bit_array<bit_count> bit_array<bit_count>::operator&(bit_array<bit_count>& bit1) {
	unsigned int min_size = min(bit1.get_size(), this->bit_arr_size);

	int* bit_1_arr = bit1.dec_to_bin();
	int* bit_2_arr = this->dec_to_bin();
	int* res_bit_arr = new int[min_size * 8];
	bit_array<bit_count> res_bit;

	transform(bit_1_arr, bit_1_arr + min_size * 8, bit_2_arr, res_bit_arr, [](int a, int b) {return (a and b); });
	res_bit.bin_to_dec(res_bit_arr);

	return res_bit;
}

template<size_t bit_count>
bit_array<bit_count> bit_array<bit_count>::operator^(bit_array<bit_count>& bit1) {
	unsigned int min_size = min(bit1.get_size(), this->bit_arr_size);

	int* bit_1_arr = bit1.dec_to_bin();
	int* bit_2_arr = this->dec_to_bin();
	int* res_bit_arr = new int[min_size * 8];
	bit_array<bit_count> res_bit;

	transform(bit_1_arr, bit_1_arr + min_size * 8, bit_2_arr, res_bit_arr, [](int a, int b) {return (a xor b); });
	res_bit.bin_to_dec(res_bit_arr);

	return res_bit;
}

template<size_t bit_count>
bool bit_array<bit_count>::operator==(bit_array<bit_count>& bit) {
	int* bit_arr_L = this->dec_to_bin();
	int* bit_arr_R = bit.dec_to_bin();

	for (int i = 0; i < this->bit_arr_size * 8; i++) {
		if (bit_arr_L[i] != bit_arr_R[i]) {
			return 0;
		}
	}

	return 1;

}

template<size_t bit_count>
bit_array<bit_count>& bit_array<bit_count>::operator=(bit_array<bit_count> bit) {
	int* bit_arr_L = this->dec_to_bin();
	int* bit_arr_R = bit.dec_to_bin();

	copy(bit_arr_R, bit_arr_R + this->bit_arr_size * 8, bit_arr_L);
	this->bit_arr_size = bit.bit_arr_size;

	this->bin_to_dec(bit_arr_L);

	return *this;
}

template<size_t bit_count>
int bit_array<bit_count>::operator[](unsigned int index) {
	int* bit_arr = this->dec_to_bin();

	while (index >= this->bit_arr.size() * 8 or index < 0) {
		cerr << "Oops! Incorrect index! Please try again: ";
		cin >> index;
	}

	return bit_arr[index];
}

template<size_t bit_count>
ostream& operator<<(std::ostream& out, bit_array<bit_count>& bit) {
	int* cout_bit = bit.dec_to_bin();
	for_each(cout_bit, cout_bit + bit.get_size() * 8, [](int a) { cout << a; });

	return out;
}

template<size_t bit_count>
bit_array<bit_count>& bit_array<bit_count>::operator++() {
	int* plus_arr = dec_to_bin();

	for (int i = 0; i < (bit_arr_size * 8) - 1; i++) {
		swap(plus_arr[i], plus_arr[i + 1]);
	}
	plus_arr[(bit_arr_size * 8) - 1] = 0;
	bin_to_dec(plus_arr);

	return *this;
}


template<size_t bit_count>
bit_array<bit_count>& bit_array<bit_count>::operator--() {
	int* minus_arr = dec_to_bin();

	for (int i = (bit_arr_size * 8) - 1; i > 0; i--) {
		swap(minus_arr[i], minus_arr[i - 1]);
	}
	minus_arr[0] = 0;
	bin_to_dec(minus_arr);

	return *this;
}

template<size_t bit_count>
void bit_array<bit_count>::bin_to_dec(int* cin_arr) {
	int num = 0, j = 1, pos = 0;

	for (int i = (bit_arr_size * 8) - 1; i >= 0; i--) {
		int temp = cin_arr[i] * (1 << (j - 1));
		if (temp) {
			num += temp;
		}
		if (j == 8) {
			bit_arr[pos] = num;
			num = 0;
			pos++;
			j = 1;
			continue;
		}
		j++;
	}
}

template<size_t bit_count>
int* bit_array<bit_count>::dec_to_bin(void) {
	int* cout_arr = new int[bit_arr.size() * 8];
	for (int i = 0; i < bit_arr.size() * 8; i++) {
		cout_arr[i] = 0;
	}
	unsigned int reminder;
	unsigned char next_step;
	int iter = (bit_arr_size * 8) - 1;

	for (int i = 0; i < bit_arr.size(); i++) {
		next_step = bit_arr[i];

		for (int j = 0; j < 8; j++) {
			reminder = next_step % 2;
			next_step /= 2;
			cout_arr[iter] = reminder;
			iter--;
		}
	}

	return cout_arr;
}

template<size_t bit_count>
unsigned int bit_array<bit_count>::get_size(void) {
	return bit_arr.size();
}

template <typename type>
int find_element_in_array(type* arr, type val, int size) {
	int position = -1;

	for (int i = 0; i < size; i++) {
		if (arr[i] == val) {
			position = i;
			break;
		}
	}

	if (position == -1) {
		return size;
	}
	else {
		return position;
	}
}

template<size_t bit_count>
void bit_array<bit_count>::fill_by_val(int value_0or1) {
	int* bit = this->dec_to_bin();

	fill(bit, bit + bit_arr.size() * 8, value_0or1);

	this->bin_to_dec(bit);
}

template<size_t bit_count>
auto bit_array<bit_count>::find_first_not_zero_bit() {
	int* bit = dec_to_bin();

	return find_if(bit, bit + bit_arr_size * 8 - 1, [](int a) { if (a == 1) return 1; return 0; });
}

template<size_t bit_count>
auto bit_array<bit_count>::queue_insert(int value, priority_queue<int> p_queue) {
	p_queue.push(value);
	return p_queue;
}

template<size_t bit_count>
void bit_array<bit_count>::queue_cout(priority_queue<int> p_queue) {
	if (p_queue.empty()) {
		cerr << "There is nothing to print." << endl;
		return;
	}
	while (!p_queue.empty()) {
		cout << p_queue.top() << "  ";
		p_queue.pop();
	}

	return;
}