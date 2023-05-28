#include <iostream>

#include <map>
#include <unordered_set>
#include <iterator>
#include <queue>

#include "lab10_header.h"
#include "lab10_source.cpp"
using namespace std;

int main(void) {
	vector<char> keys;
	vector<int> keys1;
	int bit_num;
	int ans;
	multimap<char, int> mmap;
	unordered_multiset<int> un_mset;
	priority_queue<int> p_queue;

	bit_array<1> bit_par_1;
	bit_array<9> bit_par_9;
	bit_array<256> bit_par_256;

	bit_par_1.fill_by_val(0);
	bit_par_9.fill_by_val(0);
	bit_par_256.fill_by_val(0);

	cout << "what size of array you want to use: " << endl
		<< "1. 1 bit" << endl
		<< "2. 9 bit" << endl
		<< "3. 256 bit" << endl;

	cin >> bit_num;
	while (bit_num > 3 or bit_num < 1) {
		cerr << "Choose the size from list: ";
		cin >> bit_num;
	}
	system("cls");

	switch (bit_num) {
	case(1):
		cout << "Standart array : " << bit_par_1 << endl;
		break;
	case(2):
		cout << "Standart array : " << bit_par_9 << endl;
		break;
	case(3):
		cout << "Standart array : " << bit_par_256 << endl;
		break;
	}

	while (true) {
		cout << "\nMenu:" << endl;
		cout << "1. Enter the array;" << endl
			<< "2. Show the array;" << endl
			<< "3. XOR;" << endl
			<< "4. OR" << endl
			<< "5. AND" << endl
			<< "6. Set bit by index" << endl
			<< "7. How much by value" << endl
			<< "8. <<" << endl
			<< "9. >>" << endl
			<< "10. multimap set keys" << endl
			<< "11. multimap get value by key" << endl
			<< "12. multimap delete" << endl
			<< "13. multimap insert" << endl
			<< "14. unordered_multiset set keys" << endl
			<< "15. unordered_multiset get value by key" << endl
			<< "16. unordered_multiset delete" << endl
			<< "17. unordered_multiset insert" << endl
			<< "18. unordered_multiset print" << endl
			<< "19. multimap print" << endl
			<< "20. insert in queue" << endl
			<< "21. print queue" << endl;
		
		cin >> ans;
		while (ans > 21 or ans < 1) {

			cerr << "Choose the option from list: ";
			cin >> ans;

		}
		system("cls");

		bit_array<1> bit_par_1_num2, res_par_1;
		bit_array<9> bit_par_9_num2, res_par_9;
		bit_array<256> bit_par_256_num2, res_par_256;
		int val;
		int value;

		char key;
		int key_int;
		multimap<char, int>::const_iterator it;
		unordered_multiset<int>::iterator iter;

		switch (bit_num) {
		case(1):

			switch (ans) {
			case(1):

				cout << "Enter the array:" << endl;
				cin >> bit_par_1;
				system("cls");
				break;

			case(2):
				cout << bit_par_1.find_first_not_zero_bit() << " : " << *bit_par_1.find_first_not_zero_bit() << endl;
				cout << bit_par_1 << endl;
				break;

			case(3):

				cout << "Enter second array: " << endl;
				cin >> bit_par_1_num2;
				res_par_1 = bit_par_1 ^ bit_par_1_num2;
				cout << bit_par_1 << " ^ " << bit_par_1_num2 << " = " << res_par_1 << endl;
				break;

			case(4):

				cout << "Enter second array: " << endl;
				cin >> bit_par_1_num2;
				res_par_1 = bit_par_1 | bit_par_1_num2;
				cout << bit_par_1 << " | " << bit_par_1_num2 << " = " << res_par_1 << endl;
				break;

			case(5):

				cout << "Enter second array: " << endl;
				cin >> bit_par_1_num2;
				res_par_1 = bit_par_1 & bit_par_1_num2;
				cout << bit_par_1 << " & " << bit_par_1_num2 << " = " << res_par_1 << endl;
				break;

			case(6):

				int index;
				cout << "Enter the index and value(1 or 0): ";
				cin >> index >> val;
				bit_par_1.set_this_bit(index, val);
				cout << bit_par_1 << endl;
				break;

			case(7):

				cout << "Enter the value(1 or 0): ";
				cin >> val;
				cout << bit_par_1.how_much(val) << endl;
				break;

			case(8):

				++bit_par_1;
				cout << bit_par_1 << endl;
				break;

			case(9):

				--bit_par_1;
				cout << bit_par_1 << endl;
				break;

			case(10):

				keys.resize(1);
				cout << "Enter the keys: ";
				for (int i = 0; i < 1; i++) {
					cin >> keys[i];
				}
				mmap = bit_par_1.multimap_set_keys(keys);
				system("cls");
				break;

			case(11):

				cout << "Enter the key: ";
				cin >> key;

				value = bit_par_1.multimap_get(key, mmap);
				if (value == -1) {
					cerr << "Not found!" << endl;
					break;
				}
				cout << "value by key: " << value << endl;
				break;

			case(12):

				cout << "Enter the key: ";
				cin >> key;
				mmap = bit_par_1.multimap_delete(key, mmap);

				it = mmap.begin();
				while (it != mmap.end()) {
					cout << it->first << " - " << it->second << endl;
					it++;
				}
				break;

			case(13):
				cout << "Enter the key and value: ";
				cin >> key >> value;
				mmap = bit_par_1.multimap_insert(key, value, mmap);

				it = mmap.begin();
				while (it != mmap.end()) {
					cout << it->first << " - " << it->second << endl;
					it++;
				}
				break;

			case(14):

				keys1.resize(1);
				cout << "Enter the keys: ";
				for (int i = 0; i < 1; i++) {
					cin >> keys1[i];
				}
				un_mset = bit_par_1.un_multiset_set_keys(keys1);
				system("cls");
				break;

			case(15):

				cout << "Enter the key: ";
				cin >> key_int;

				value = bit_par_1.un_multiset_get(key_int, un_mset);
				if (value == -1) {
					cerr << "Not found!" << endl;
					break;
				}
				cout << "value by key: " << value << endl;
				break;

			case(16):

				cout << "Enter the key: ";
				cin >> key_int;
				un_mset = bit_par_1.un_multiset_delete(key_int, un_mset);

				iter = un_mset.begin();
				while (iter != un_mset.end()) {
					cout << *iter << " ";
					iter++;
				}
				break;

			case(17):

				cout << "Enter the key and value: ";
				cin >> key_int;
				un_mset = bit_par_1.un_multiset_insert(key_int, un_mset);

				iter = un_mset.begin();
				while (iter != un_mset.end()) {
					cout << *iter << " ";
					iter++;
				}
				break;

			case(18):
				
				bit_par_1.un_multiset_cout(un_mset);
				break;

			case(19):

				bit_par_1.multimap_cout(mmap);
				break;
			
			case(20):
				
				cout << "How many: ";
				int n;
				cin >> n;
				cout << "Enter the value: ";
				for (int i = 0; i < n; i++) {
					cin >> value;
					p_queue = bit_par_1.queue_insert(value, p_queue);
				}
				break;

			case(21):

				if (!p_queue.empty()) {
					cout << "Queue: ";
				}
				bit_par_1.queue_cout(p_queue);
				break;

			}

			break;

		case(2):

			switch (ans) {

			case(1):

				cout << "Enter the array:" << endl;
				cin >> bit_par_9;
				system("cls");
				break;

			case(2):
				
				cout << bit_par_9.find_first_not_zero_bit() << " : " << *bit_par_9.find_first_not_zero_bit() << endl;
				cout << bit_par_9 << endl;
				break;

			case(3):

				cout << "Enter second array: " << endl;
				cin >> bit_par_9_num2;
				res_par_9 = bit_par_9 ^ bit_par_9_num2;
				cout << bit_par_9 << " ^ " << endl << bit_par_9_num2 << " = " << endl << res_par_9 << endl;
				break;

			case(4):

				cout << "Enter second array: " << endl;
				cin >> bit_par_9_num2;
				res_par_9 = bit_par_9 | bit_par_9_num2;
				cout << bit_par_9 << " | " << endl << bit_par_9_num2 << " = " << endl << res_par_9 << endl;
				break;

			case(5):

				cout << "Enter second array: " << endl;
				cin >> bit_par_9_num2;
				res_par_9 = bit_par_9 & bit_par_9_num2;
				cout << bit_par_9 << " & " << endl << bit_par_9_num2 << " = " << endl << res_par_9 << endl;
				break;

			case(6):

				int index;
				cout << "Enter the index and value(1 or 0): ";
				cin >> index >> val;
				while (bit_par_9[index] == val) {
					cout << "This bit is already equals: " << val << endl;
					cout << "Enter another index and value(1 or 0): ";
					cin >> index >> val;
				}
				bit_par_9.set_this_bit(index, val);
				cout << bit_par_9 << endl;
				break;

			case(7):

				cout << "Enter the value(1 or 0): ";
				cin >> val;
				cout << bit_par_9.how_much(val) << endl;
				break;

			case(8):

				++bit_par_9;
				cout << bit_par_9 << endl;
				break;

			case(9):

				--bit_par_9;
				cout << bit_par_9 << endl;
				break;

			case(10):

				keys.resize(9);
				cout << "Enter the keys: ";
				for (int i = 0; i < 9; i++) {
					cin >> keys[i];
				}
				mmap = bit_par_9.multimap_set_keys(keys);
				system("cls");
				break;

			case(11):

				cout << "Enter the key: ";
				cin >> key;

				value = bit_par_9.multimap_get(key, mmap);
				if (value == -1) {
					cerr << "Not found!" << endl;
					break;
				}
				cout << "value by key: " << value << endl;
				break;

			case(12):

				cout << "Enter the key: ";
				cin >> key;
				mmap = bit_par_9.multimap_delete(key, mmap);

				it = mmap.begin();
				while (it != mmap.end()) {
					cout << it->first << " - " << it->second << endl;
					it++;
				}
				break;
			case(13):
				
				cout << "Enter the key and value: ";
				cin >> key >> value;
				mmap = bit_par_9.multimap_insert(key, value, mmap);

				it = mmap.begin();
				while (it != mmap.end()) {
					cout << it->first << " - " << it->second << endl;
					it++;
				}
				break;
				
			case(14):

				keys1.resize(9);
				cout << "Enter the keys: ";
				for (int i = 0; i < 9; i++) {
					cin >> keys1[i];
				}
				un_mset = bit_par_9.un_multiset_set_keys(keys1);
				system("cls");
				break;

			case(15):

				cout << "Enter the key: ";
				cin >> key_int;

				value = bit_par_9.un_multiset_get(key_int, un_mset);
				if (value == -1) {
					cerr << "Not found!" << endl;
					break;
				}
				cout << "value by key: " << value << endl;
				break;

			case(16):

				cout << "Enter the key: ";
				cin >> key_int;
				un_mset = bit_par_9.un_multiset_delete(key_int, un_mset);

				iter = un_mset.begin();
				while (iter != un_mset.end()) {
					cout << *iter << " ";
					iter++;
				}
				break;

			case(17):
				
				cout << "Enter the key: ";
				cin >> key_int;
				un_mset = bit_par_9.un_multiset_insert(key_int, un_mset);

				iter = un_mset.begin();
				while (iter != un_mset.end()) {
					cout << *iter << " ";
					iter++;
				}
				break;

			case(18):

				bit_par_9.un_multiset_cout(un_mset);
				break;

			case(19):

				bit_par_9.multimap_cout(mmap);
				break;

			case(20):

				cout << "How many: ";
				int n;
				cin >> n;
				cout << "Enter the value: ";
				for (int i = 0; i < n; i++) {
					cin >> value;
					p_queue = bit_par_9.queue_insert(value, p_queue);
				}
				break;

			case(21):

				if (!p_queue.empty()) {
					cout << "Queue: ";
				}
				bit_par_9.queue_cout(p_queue);
				break;
			}

			break;

		case(3):

			switch (ans) {
			case(1):

				cout << "Enter the array:" << endl;
				cin >> bit_par_256;
				system("cls");
				break;

			case(2):

				cout << bit_par_256.find_first_not_zero_bit() << " : " << *bit_par_256.find_first_not_zero_bit() << endl;
				cout << bit_par_256 << endl;
				break;

			case(3):

				cout << "Enter second array: " << endl;
				cin >> bit_par_256_num2;
				res_par_256 = bit_par_256 ^ bit_par_256_num2;
				cout << bit_par_256 << " ^ " << bit_par_256_num2 << " = " << res_par_256 << endl;
				break;

			case(4):

				cout << "Enter second array: " << endl;
				cin >> bit_par_256_num2;
				res_par_256 = bit_par_256 | bit_par_256_num2;
				cout << bit_par_256 << " | " << bit_par_256_num2 << " = " << res_par_256 << endl;
				break;

			case(5):

				cout << "Enter second array: " << endl;
				cin >> bit_par_256_num2;
				res_par_256 = bit_par_256 & bit_par_256_num2;
				cout << bit_par_256 << " & " << bit_par_256_num2 << " = " << res_par_256 << endl;
				break;

			case(6):

				int index;
				cout << "Enter the index and value(1 or 0): ";
				cin >> index >> val;
				bit_par_256.set_this_bit(index, val);
				cout << bit_par_256 << endl;
				break;

			case(7):

				cout << "Enter the value(1 or 0): ";
				cin >> val;
				cout << bit_par_256.how_much(val) << endl;
				break;

			case(8):

				++bit_par_256;
				cout << bit_par_256 << endl;
				break;

			case(9):

				--bit_par_256;
				cout << bit_par_256 << endl;
				break;

			case(10):

				keys.resize(256);
				cout << "Enter the keys: ";
				for (int i = 0; i < 256; i++) {
					cin >> keys[i];
				}
				mmap = bit_par_256.multimap_set_keys(keys);
				system("cls");
				break;

			case(11):

				cout << "Enter the key: ";
				cin >> key;

				value = bit_par_256.multimap_get(key, mmap);
				if (value == -1) {
					cerr << "Not found!" << endl;
					break;
				}
				cout << "value by key: " << value << endl;
				break;

			case(12):

				cout << "Enter the key: ";
				cin >> key;
				mmap = bit_par_256.multimap_delete(key, mmap);

				it = mmap.begin();
				while (it != mmap.end()) {
					cout << it->first << " - " << it->second << endl;
					it++;
				}
				break;

			case(13):

				cout << "Enter the key and value: ";
				cin >> key >> value;
				mmap = bit_par_256.multimap_insert(key, value, mmap);

				it = mmap.begin();
				while (it != mmap.end()) {
					cout << it->first << " - " << it->second << endl;
					it++;
				}
				break;

			case(14):

				keys1.resize(256);
				cout << "Enter the keys: ";
				for (int i = 0; i < 256; i++) {
					cin >> keys1[i];
				}
				un_mset = bit_par_256.un_multiset_set_keys(keys1);
				system("cls");
				break;

			case(15):

				cout << "Enter the key: ";
				cin >> key_int;

				value = bit_par_256.un_multiset_get(key_int, un_mset);
				if (value == -1) {
					cerr << "Not found!" << endl;
					break;
				}
				cout << "value by key: " << value << endl;
				break;

			case(16):

				cout << "Enter the key: ";
				cin >> key;
				un_mset = bit_par_256.un_multiset_delete(key, un_mset);

				iter = un_mset.begin();
				while (iter != un_mset.end()) {
					cout << *iter << " ";
					iter++;
				}
				break;

			case(17):

				cout << "Enter the key and value: ";
				cin >> key >> value;
				un_mset = bit_par_256.un_multiset_insert(key, un_mset);

				iter = un_mset.begin();
				while (iter != un_mset.end()) {
					cout << *iter << " ";
					iter++;
				}
				break;

			case(18):

				bit_par_256.un_multiset_cout(un_mset);
				break;

			case(19):

				bit_par_256.multimap_cout(mmap);
				break;

			case(20):
				cout << "How many: ";
				int n;
				cin >> n;
				cout << "Enter the value: ";
				for (int i = 0; i < n; i++) {
					cin >> value;
					p_queue = bit_par_256.queue_insert(value, p_queue);
				}
				break;

			case(21):

				if (!p_queue.empty()) {
					cout << "Queue: ";
				}
				bit_par_256.queue_cout(p_queue);
				break;
			}
			
			break;
			
		}
	}
}