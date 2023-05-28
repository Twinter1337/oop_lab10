#ifndef OOP_LAB5_HEADER_H
#define OOP_LAB5_HEADER_H
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <unordered_set>

template <size_t bit_count>
class bit_array {
private:
	unsigned int bit_arr_size;
	std::vector<unsigned char> bit_arr;
public:
	bit_array();
	bit_array(const bit_array<bit_count>& other);
	bit_array(bit_array<bit_count>&& other);
	~bit_array();
	void set_this_bit(unsigned int index, int value_1or0);
	int how_much(int value_1or0);
	bit_array<bit_count> operator|(bit_array<bit_count>& bit2);
	bit_array<bit_count> operator&(bit_array<bit_count>& bit2);
	bit_array<bit_count> operator^(bit_array<bit_count>& bit1);
	bit_array& operator++();
	bit_array& operator--();

	std::multimap<char, int> multimap_set_keys(std::vector<char> keys);
	auto multimap_get(char key, std::multimap<char, int> mmap);
	auto multimap_delete(char key, std::multimap<char, int> mmap);
	auto multimap_insert(char key, int val, std::multimap<char, int> mmap);
	void multimap_cout(std::multimap<char, int> mmap);

	std::unordered_multiset<int> un_multiset_set_keys(std::vector<int> keys);
	auto un_multiset_get(int key, std::unordered_multiset<int> un_mset);
	auto un_multiset_delete(int key, std::unordered_multiset<int> un_mset);
	auto un_multiset_insert(int key, std::unordered_multiset<int> un_mset);
	void un_multiset_cout(std::unordered_multiset<int> mmap);

	auto queue_insert(int value, std::priority_queue<int> p_queue);
	void queue_cout(std::priority_queue<int> p_queue);

	template<size_t bit_count>
	friend std::ostream& operator<<(std::ostream& out, bit_array<bit_count>& bit);

	template<size_t bit_count>
	friend std::istream& operator>>(std::istream& in, bit_array<bit_count>& bit);

	bool operator==(bit_array<bit_count>& bit);
	int operator[](unsigned int index);
	bit_array<bit_count>& operator=(bit_array<bit_count> bit);
	unsigned int get_size(void);
	void bin_to_dec(int* cin_arr);
	int* dec_to_bin(void);
	void fill_by_val(int value_0or1);
	auto find_first_not_zero_bit();
};

template <typename type>
int find_element_in_array(type* arr, type val, int size);

#endif
