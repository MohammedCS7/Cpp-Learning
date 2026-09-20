#pragma once
#include "clsDblLinkedList.h"
template <class T>
class clsMyQueue
{
protected:
	clsDblLinkedList<T> _List;

public:
	void push(T value)
	{
		_List.InsertAtEnd(value);
	}
	void pop()
	{
		_List.DeleteFirst();
	}
	int Size()
	{
		return _List.Size();
	}
	void Print()
	{
		_List.PrintList();
	}
	bool IsEmpty()
	{
		return _List.IsEmpty();
	}
	T front()
	{
		return _List.GetValue(0);
	}
	T back()
	{
		return _List.GetValue(_List.Size() - 1);
	}
	T GetValue(int index)
	{
		return _List.GetValue(index);
	}
	void Reverse()
	{
		_List.Reverse();
	}
	bool UpdateValue(int index,T newValue)
	{
		return _List.UpdateValue(index, newValue);
	}
	void InsertAfter(int index, T value)
	{
		_List.InsertAfter(index, value);
	}
	void InsertAtFront(T value)
	{
		_List.InsertAtFirst(value);
	}
	void InsertAtBack(T value)
	{
		_List.InsertAtEnd(value);
	}
	void Clear()
	{
		_List.Clear();
	}
};

