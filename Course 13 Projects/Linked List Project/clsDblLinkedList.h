#pragma once
#include <iostream>
using namespace std;
template <class T>
class clsDblLinkedList
{
public:
	class Node
	{
	public:
		T value;
		Node* next;
		Node* prev;
	};
protected:
	Node* _Head = NULL;
	int _Size = 0;

	static void _PrintNode(Node* node)
	{
		if (node->prev == NULL)
		{
			cout << "NULL <---> ";
		}
		cout << node->value << " <---> ";
		if (node->next == NULL)
			cout << "NULL";
	}


public:
	static void InsertAtFirst(Node*& head, T value)
	{
		Node* newNode = new Node();
		newNode->value = value;
		newNode->prev = NULL;
		if (head == NULL)
		{
			head = newNode;
			head->next = NULL;
			return;
		}
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
		
	}

	void InsertAtFirst(T value)
	{
		InsertAtFirst(_Head, value);
		_Size++;
	}

	static void InsertAtEnd(Node*& head, T value)
	{
		Node* newNode = new Node();
		newNode->value = value;
		newNode->next = NULL;
		if (head == NULL)
		{
			newNode->prev = NULL;
			head = newNode;
			return;
		}
		Node* current = head;
		while (current->next != NULL)
			current = current->next;
		current->next = newNode;
		newNode->prev = current;
	}

	void InsertAtEnd(T value)
	{
		InsertAtEnd(_Head, value);
		_Size++;
	}

	static Node* Find(Node* head, T value)
	{
		while (head != NULL && head->value != value)
			head = head->next;
		return head;
	}

	Node* Find(T value)
	{
		return Find(_Head, value);
	}

	 void InsertAfter(Node* target, T value)
	{
		if (target == NULL)
			return;
		Node* newNode = new Node();

		newNode->value = value;

		if (target->next != NULL)
		{
			target->next->prev = newNode;
		}
		newNode->prev = target;
		newNode->next = target->next;
		target->next = newNode;
		_Size++;
	}

	static void DeleteNode(Node*& head, Node* target)
	{
		if (head == NULL || target == NULL)
			return;
		if (target == head)
		{
			if (head->next != NULL)
			{
				head = head->next;
				head->prev = NULL;
			}
			else
			{
				head = NULL;
			}
			
		}
		else if (target->next == NULL)
		{
			target->prev->next = NULL;
		}
		else
		{
			target->prev->next = target->next;
			target->next->prev = target->prev;
		}
		delete target;
	}

	void DeleteNode(Node* target)
	{
		DeleteNode(_Head, target);
		_Size--;
	}

	static void DeleteLast(Node*& head)
	{
		Node* current = head;
		while (current->next != NULL)
			current = current->next;
		if (current->prev != NULL)
		{
			current->prev->next = NULL;
		}
		else
			head = NULL;

		delete current;
	}

	void DeleteLast()
	{
		DeleteLast(_Head);
		_Size--;
	}

	static void DeleteFirst(Node*& head)
	{
		if (head == NULL)
			return;
		if (head->next != NULL)
		{
			head->next->prev = NULL;
		}
		Node* current = head;
		head = head->next;
		delete current;
	}

	void DeleteFirst()
	{
		DeleteFirst(_Head);
		_Size--;
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return (_Size == 0);
	}

	void Clear()
	{
		while (_Size != 0)
			DeleteFirst();
	}

	static void Reverse(Node*& head)
	{
		Node* current = head;
		Node* temp = nullptr;
		

		while (current != nullptr)
		{
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			current = current->prev;
		}
		if (temp != nullptr)
			head = temp->prev;
		
	}

	void Reverse()
	{
		Reverse(_Head);
	}

	static Node* GetNode(Node* head, int index)
	{
		if (index < 0) return nullptr;
		
		while (head != nullptr && index-- != 0)
		{
			head = head->next;
		}
			return head;
	}

	Node* GetNode(int index)
	{
		return GetNode(_Head, index);
	}

	static T GetValue(Node* head, int index)
	{
		Node* N = GetNode(head, index);
		if (N == nullptr)
			return T();
		else
			return N->value;
	}

	T GetValue(int index)
	{
		return GetValue(_Head, index);
	}

	static bool UpdateValue(Node* head,int index, T newValue)
	{
		Node* N = GetNode(head, index);
		if (N != nullptr)
		{
			N->value = newValue;
			return true;
		}
		else
			throw out_of_range("Index out of range!");
		return false;
	}

	bool UpdateValue(int index, T newValue)
	{
		return UpdateValue(_Head, index, newValue);
	}

	bool InsertAfter(int index, T value)
	{
		Node* N = GetNode(index);
		if (N != nullptr)
		{
			InsertAfter(N, value);
			return true;
		}
		return false;
	}

	static void PrintList(Node* head)
	{
		while (head != NULL)
		{
			_PrintNode(head);
			head = head->next;
		}
	}

	void PrintList()
	{
		PrintList(_Head);
	}

};

