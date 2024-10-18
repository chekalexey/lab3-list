#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__


template <class T>
class List{
	struct node {
		T value;
		node* next;
		node() {
			value = 0;
			next = nullptr;
		}
		node(T value, node* adr) {
			node->value = value;
			node->next = adr;
		}
	};
	node* first;
public:/*
	List();
	List(int n, T deflt = T());
	~List();
	List(const List& l);
	List operator=(const List& l);
	T& operator[](int index);
	node* insert(T value, node* prev);
	node* insert_front(T value, node* prev);
	node* erase(node* prev);
	node* erase_front(node* prev);
	node* find(T value);
	node* get_first();
	size_t size();*/
};


#endif
