#include "List.h"

template<typename T> bool List<T>::HasNext()
{
	if (this->Size != 0 && cur != nullptr)
		return true;
	else
		return false;
}

template<typename T> void List<T>::iterator(Node* curent)
{
	cur = curent;
}


template<typename T> void List<T>::push_back(T obj) { // ���������� � ����� ������ bc
	if (head != NULL) {
		this->tail->Next = new Node(obj);
		tail = tail->Next;
	}
	else {
		this->head = new Node(obj);
		this->tail = this->head;
	}
	Size++;
}
template<typename T> void List<T>::push_front(T obj) { // ���������� � ������ ������ bc
	if (head != NULL) {
		Node* current = new Node;
		current->data = obj;
		current->Next = this->head;
		this->head = current;
	}
	else {
		this->head = new Node(obj);
	}
	this->Size++;
}
template<typename T> void List<T>::pop_back() { // �������� ���������� �������� bc
	if (head != NULL) {
		Node* current = head;
		while (current->Next != tail)//�� ���� ���� �������������
			current = current->Next;
		delete tail;
		tail = current;
		tail->Next = NULL;
		Size--;
	}
	else throw std::out_of_range("out_of_range");
}
template<typename T> void List<T>::pop_front() { // �������� ������� �������� bc-+
	if (head != NULL) {
		Node* current = head;
		head = head->Next;
		delete current;
		Size--;
	}
	else throw std::out_of_range("out_of_range");
}
template<typename T> void List<T>::insert(T obj, size_t k) {// ���������� �������� �� ������� (������� ����� ���������, ������� ��� ����� �������� �� ����� �������) bc
	if (k >= 0 && this->Size > k) {
		if (this->head != NULL) {
			if (k == 0)
				this->push_front(obj);
			else
				if (k == this->Size - 1)
					this->push_back(obj);
				else
				{
					Node* current = new Node;//��� ���������� ��������
					Node* current1 = head;//��� ������ ����� ��������
					for (int i = 0; i < k - 1; i++) {
						current1 = current1->Next;
					}
					current->data = obj;
					current->Next = current1->Next;//������������� �� ���� �������
					current1->Next = current;
					Size++;
				}
		}
	}
	else {
		throw std::out_of_range("out_of_range");
	}
}
template<typename T> T List<T>::at(size_t k) {// ��������� �������� �� ������� bc
	if (this->head != NULL && k >= 0 && k <= this->Size - 1) {
		if (k == 0)
			return this->head->data;
		else
			if (k == this->Size - 1)
				return this->tail->data;
			else
			{
				Node* current = head;
				for (int i = 0; i < k; i++) {
					current = current->Next;
				}
				return current->data;
			}
	}
	else {
		throw std::out_of_range("out_of_range");
	}
}



template<typename T> void List<T>::swap(size_t index_one, size_t index_two)
{
	T temp_info = this->at(index_one);
	int temp_count = this->atCount(index_one);
	this->set_with_count(index_one, this->at(index_two), this->atCount(index_two));
	this->set_with_count(index_two, temp_info, temp_count);
}
template<typename T> void List<T>::remove(int k) { // �������� �������� �� ������� bc
	if (head != NULL && k >= 0 && k <= Size - 1) {
		if (k == 0) this->pop_front();
		else
			if (k == this->Size - 1) this->pop_back();
			else
				if (k != 0) {
					Node* current = head;
					for (int i = 0; i < k - 1; i++) {//��������� �� �����������
						current = current->Next;
					}

					Node* current1 = current->Next;
					current->Next = current->Next->Next;
					delete current1;
					Size--;
				}
	}
	else {
		throw std::out_of_range("out_of_range");
	}
}
template<typename T> size_t List<T>::get_size() { // ��������� ������� ������ bc
	return Size;
}
template<typename T> void List<T>::print_to_console() { // ����� ��������� ������ � ������� ����� �����������, �� ������������ at bc
	if (this->head != NULL) {
		Node* current = head;
		for (int i = 0; i < Size; i++) {
			cout << current->data;
			current = current->Next;
		}
	}
}

template<typename T> void List<T>::print_to_console_with_code() { // ����� ��������� ������ � ������� ����� �����������, �� ������������ at bc
	if (this->head != NULL) {
		Node* current = head;
		cout << endl;
		for (int i = 0; i < Size; i++) {
			cout << "|" << current->data << " - ";
			current->code->print_to_console();
			cout << endl;
			current = current->Next;
		}
	}
}
template<typename T> void List<T>::clear() { // �������� ���� ��������� ������
	if (head != NULL) {
		Node* current = head;
		while (head != NULL) {
			current = current->Next;
			delete head;
			head = current;
		}
		Size = 0;
	}
}
template<typename T> void List<T>::set(size_t k, T obj)  // ������ �������� �� ������� �� ������������ ������� 
{
	if (this->head != NULL && this->get_size() >= k && k >= 0) {
		Node* current = head;
		for (int i = 0; i < k; i++) {
			current = current->Next;
		}
		current->data = obj;
	}
	else {
		throw std::out_of_range("out_of_range");
	}
}


template<typename T> bool List<T>::isEmpty() { // �������� �� ������� ������ bc
	return (bool)(head);
}
template<typename T> void List<T>::reverse() { // ������ ������� ��������� � ������
	int Counter = Size;
	Node* HeadCur = NULL;
	Node* TailCur = NULL;
	for (int j = 0; j < Size; j++) {
		if (HeadCur != NULL) {
			if (head != NULL && head->Next == NULL) {
				TailCur->Next = head;
				TailCur = head;
				head = NULL;
			}
			else {
				Node* cur = head;
				for (int i = 0; i < Counter - 2; i++)
					cur = cur->Next;
				TailCur->Next = cur->Next;
				TailCur = cur->Next;
				cur->Next = NULL;
				tail = cur;
				Counter--;
			}
		}
		else {
			HeadCur = tail;
			TailCur = tail;
			Node* cur = head;
			for (int i = 0; i < Size - 2; i++)
				cur = cur->Next;
			tail = cur;
			tail->Next = NULL;
			Counter--;
		}
	}
	head = HeadCur;
	tail = TailCur;
}




template<typename T> T List<T>::getData()
{
	if (cur != nullptr) return this->cur->data;
	else return NULL;
}



