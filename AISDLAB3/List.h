#include<iostream>

using namespace std;
template<class T>
class List
{
private:
	class Node {
	public:
		Node(T data = T(), Node* Next = NULL) {
			this->data = data;
			this->Next = Next;
		}
		Node(T data, int count) :data(data), Next(NULL) {};
		Node* Next;
		T data;
	};

	Node* head;
	Node* tail;
	Node* cur;
	int Size;
public:



	void iterator(Node* curent);//create iterator
	bool HasNext();//we check have next element
	void push_back(T obj); // ���������� � ����� ������ bc
	void push_front(T obj); // ���������� � ������ ������ bc
	void pop_back(); // �������� ���������� �������� bc
	void pop_front(); // �������� ������� �������� bc-+
	void insert(T obj, size_t k); // ���������� �������� �� ������� (������� ����� ���������, ������� ��� ����� �������� �� ����� �������) bc
	T at(size_t k); // ��������� �������� �� ������� bc
	void swap(size_t index_one, size_t index_two);//swap of 2 elements
	void remove(int k); // �������� �������� �� ������� bc
	size_t get_size(); // ��������� ������� ������ bc
	void print_to_console(); // ����� ��������� ������ � ������� ����� �����������, �� ������������ at bc
	void print_to_console_with_code();
	void clear();  // �������� ���� ��������� ������
	void set(size_t k, T obj);  // ������ �������� �� ������� �� ������������ ������� 
	bool isEmpty(); // �������� �� ������� ������ bc
	void reverse();  // ������ ������� ��������� � ������
	List(Node* head = NULL, Node* tail = NULL, int Size = 0) :head(head), tail(tail), Size(Size) {}
	~List() {
		if (head != NULL) {
			this->clear();
		}
	};
	Node* getHead()//geting head
	{
		return this->head;
	}

	Node* Next()//geting current element from iterator, move to next element
	{
		Node* temp;
		temp = cur;
		cur = cur->Next;
		return temp;
	}
	T getData();//geting data of elements
};