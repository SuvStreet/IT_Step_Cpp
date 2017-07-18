#pragma once

template <typename T>
class ForwardList {
	struct node {
		T data;
		node* next = nullptr;
	};
	node* head = 0;
	node* tail = 0;
	size_t list_size = 0;

public:
	ForwardList() {}
	~ForwardList() {
		while(!empty()) {
			pop_front();
		}
	}

	ForwardList(const ForwardList&) = delete;
	ForwardList& operator=(const ForwardList&) = delete;

	size_t size() const;
	bool empty() const;

	void push_back(const T&);
	void push_front(const T&);
	bool insert(const T&, const T&);

	T pop_back();
	T pop_front();
	bool erase(const T&);

	void print();

private:
	node* create_node(const T&);
	void create_first_node(const T&);
	node* find_node(const T&);
	node* find_previous_node(const T&);
};

template<typename T>
T ForwardList<T>::pop_back() {
	if (!empty()) {
		if (list_size == 1) {
			T value = head->data;
			delete head;
			head = tail = nullptr;
			--list_size;
			return value;
		}
		T data = tail->data;
		node* ptr = head;
		while (ptr->next->next != nullptr) {
			ptr = ptr->next;
		}
		ptr->next = nullptr;
		delete tail;
		tail = ptr;
		--list_size;
		if (list_size == 0) {
			head = tail = nullptr;
		}
		return data;
	}
	else throw std::logic_error("Error: empty list.");
}

template<typename T>
T ForwardList<T>::pop_front() {
	if (!empty()) {
		T data = head->data;
		node* ptr = head;
		head = head->next;
		--list_size;
		delete ptr;
		if (list_size == 0) {
			head = tail = nullptr;
		}
		return data;
	}
	else throw std::logic_error("Error: empty list.");
}

template<typename T>
size_t ForwardList<T>::size() const {
	return list_size;
}

template<typename T>
bool ForwardList<T>::empty() const {
	return (list_size == 0 ? true : false);
}

template<typename T>
void ForwardList<T>::print() {
	node* temp = head;
	while (temp != nullptr) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

template<typename T>
typename ForwardList<T>::node* ForwardList<T>::create_node(const T& value) {
	node* ptr = new node;
	ptr->data = value;
	ptr->next = nullptr;
	return ptr;
}

template<typename T>
void ForwardList<T>::create_first_node(const T& value) {
	node* temp = create_node(value);
	head = temp;
	tail = temp;
}

template<typename T>
void ForwardList<T>::push_front(const T& value) {
	if (empty()) { create_first_node(value); }
	else {
		node* temp = create_node(value);
		temp->next = head;
		head = temp;
	}
	++list_size;
}

template<typename T>
void ForwardList<T>::push_back(const T& value) {
	if (!empty()) { 
		node* temp = create_node(value);
		tail->next = temp;
		tail = temp;
	}
	else { create_first_node(value); }
	++list_size;
}

template<typename T>
typename ForwardList<T>::node* ForwardList<T>::find_node(const T& value) {
	if (empty()) { return nullptr; }
	
	node* temp = head;
	while (temp != nullptr) {
		if (temp->data == value) return temp;
		temp = temp->next;
	}
	return nullptr;
}

template<typename T>
typename ForwardList<T>::node* ForwardList<T>::find_previous_node(const T& value) {
	if (empty()) { return nullptr; }
	node* temp = head;
	while (temp->next->next != nullptr) {
		if (temp->next->data == value)
			return temp;
		temp = temp->next;
	}
	return nullptr;
}

template<typename T>
bool ForwardList<T>::insert(const T& value1, const T& value2) {

	if (empty()) { return false; }
	
	node* ptr = find_node(value2);

	if (ptr == tail) {
		push_back(value1);
		return true;
	}

	if (ptr != nullptr) {
			node* ptr1 = ptr->next;
			node* temp = create_node(value1);
			ptr->next = temp;
			temp->next = ptr1;
			++list_size;
			return true;
		}
	else return false;
}

template<typename T>
bool ForwardList<T>::erase(const T& value){
	
	if (empty()) throw std::logic_error("empty_list");

	node* ptr = find_node(value);

	if (ptr == nullptr) return false;
	
	if (ptr == head) {
		pop_front();
	}
	else if (ptr == tail) {
		pop_back();
	}
	else {
		node* temp = find_previous_node(value);
		temp->next = ptr->next;
		delete ptr;
		--list_size;
		if (list_size == 0) {
			head = tail = nullptr;
		}
		return true;
	}
	return false;
}
