#ifndef __TList_H__
#define __TList_H__

#include <string>

template <class T>
class List{
	struct node {
		T value;
		node* next;
		node() {
			value = 0;
			next = nullptr;
		}
		node(T val, node* adr) {
			value = val;
			next = adr;
		}
	};
	node* first = nullptr;
public:
	class iterator {
	protected:
		node* curr;
	public:
		explicit iterator(node* node) : curr(node) {}
		iterator& operator++() {
			curr = curr->next;
			return *this;
		}
		iterator operator++(int) {
			iterator copy = *this;
			curr = curr->next;
			return copy;
		}
		T& operator*() {
			return curr->value;
		}
		T* operator->() {
			return &(curr->value);
		}
		friend bool operator!=(const iterator& it1, const iterator& it2) {
			return it1.curr != it2.curr;
		}
		friend bool operator==(const iterator& it1, const iterator& it2) {
			return it1.curr == it2.curr;
		}
	};
	iterator begin() {
		return iterator(first);
	}
	iterator end() {
		return iterator(nullptr);
	}

	List();
	List(int n, T deflt = T());
	~List();
	List(const List& l);
	List operator=(const List& l);
	T& operator[](int index);
	size_t size();
	void print();

	void reverse();
	List add(T val);

	node* insert(T val, node* prev) {
		node* tmp = new node;
		tmp->next = prev->next;
		prev->next = tmp;
		tmp->value = val;
		return tmp;
	}

	node* insert_front(T val) {
		node* tmp = new node;
		tmp->next = first;
		first = tmp;
		tmp->value = val;
		return first;
	}

	node* erase(node* prev) {
		if (!prev->next || !prev) throw "erase a non existing element";
		node* del = prev->next;
		prev->next = del->next;
		delete del;
		return prev->next;
	}

	node* erase_front() {
		if (!first) throw "erase a non existing element";
		node* del = first;
		first = del->next;
		delete del;
		return first;
	}

	node* find(T val) {
		node* cur = first;
		while (cur) {
			if (cur->value == val)
				return cur;
			cur = cur->next;
		}
		return nullptr;
	}

	node* get_first() {
		return first;
	}
};

template <class T>
inline List<T>::List() {
	node* first = new node;
}

template <class T>
inline List<T>::List(int n, T deflt = T()) {
	if (n < 0) throw "List size should be non negative";
	if (n == 0) return;

	first = new node(deflt, nullptr);
	node* cur = first;

	for (int i = 1; i < n; ++i) {
		node* tmp = new node(deflt, nullptr);
		cur->next = tmp;
		cur = cur->next;
	}
}

template <class T>
inline List<T>::List(const List& l) {
	if (!l.first) {
		first = nullptr;
	}
	first = new node(l.first->value, nullptr);
	node* cur = first;
	node* ocur = l.first;
	while (ocur->next) {
		cur->next = new node(ocur->next->value, nullptr);
		cur = cur->next;
		ocur = ocur->next;
	}
}

template <class T>
inline List<T>::~List() {
	while (first) {
		node* second = first->next;
		delete first;
		first = second;
	}
}

template <class T>
inline void List<T>::print() {
	node* cur = first;
	while (cur) {
		std::cout << cur->value << ' ';
		cur = cur->next;
	}
	std::cout << std::endl;
}

template<class T>
inline size_t List<T>::size() {
	int s = 0;
	node* cur = first;
	while (cur) {
		s++;
		cur = cur->next;
	}
	return s;
}

template <class T>
inline List<T> List<T>::operator=(const List<T>& l) {
	if (this == &l) {
		return *this;
	}

	if (!l.first) {
		first = nullptr;
		return *this;
	}

	while (first) {
		node* second = first->next;
		delete first;
		first = second;
	}

	first = new node(l.first->value, nullptr);
	node* cur = first;
	node* ocur = l.first;

	while (ocur->next) {
		cur->next = new node(ocur->next->value, nullptr);
		cur = cur->next;
		ocur = ocur->next;
	}
	return *this;
}

template <class T>
inline T& List<T>::operator[](int ind) {
	if (ind < 0) throw "out_of_range";

	node* cur = first;
	for (int i = 0; cur != nullptr; i++) {
		if (i == ind)
			return cur->value;

		cur = cur->next;
	}
	throw "out_of_range";
}

template<class T>
inline void List<T>::reverse() {
	if (!first) return;
	node* curr, * next, * prev = nullptr;
	curr = first;

	while (curr){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	first = prev;
}

template<class T>
inline List<T> List<T>::add(T val) {
	if (val < 0) throw "invalid value";

	this->reverse();
	
	if (!first)
		first = new node;

	node* curr = first;
	std::string sl = std::to_string(val);
	int accum = 0;
	int n = sl.size() - 1;

	while (curr) {
		if (curr->value > 9 || curr->value < 0) throw "invalid element";

		if (n >= 0) {
			curr->value += sl[n] - '0';
			n--;
		}

		curr->value += accum;
		if (curr->value > 9) {
			accum = 1;
			curr->value -= 10;
		}

		if (!curr->next && n >= 0) {
			node* app = new node;
			curr->next = app;
		}

		if (curr->next == nullptr && accum > 0) {
			node* dgt = new node(1, nullptr);
			curr->next = dgt;
			break;
		}
		curr = curr->next;
	}

	this->reverse();
	return *this;
}

#endif
