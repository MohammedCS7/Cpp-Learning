#pragma once
#include "clsDynamicArray.h"
template <class T>
class clsMyQueueArr
{
protected:
	clsDynamicArray<T> _Arr;

public:
	void push(T value)
	{
		_Arr.InsertAtEnd(value);
	}
	void pop()
	{
		_Arr.DeleteFirst();
	}
	int Size()
	{
		return _Arr.Size();
	}
	void Print()
	{
		_Arr.PrintList();
	}
	bool IsEmpty()
	{
		return _Arr.IsEmpty();
	}
	T front()
	{
		return _Arr.GetValue(0);
	}
	T back()
	{
		return _Arr.GetValue(_Arr.Size() - 1);
	}
	T GetValue(int index)
	{
		return _Arr.GetValue(index);
	}
	void Reverse()
	{
		_Arr.Reverse();
	}
	bool UpdateValue(int index, T newValue)
	{
		return _Arr.UpdateValue(index, newValue);
	}
	void InsertAfter(int index, T value)
	{
		_Arr.InsertAfter(index, value);
	}
	void InsertAtFront(T value)
	{
		_Arr.InsertAtFirst(value);
	}
	void InsertAtBack(T value)
	{
		_Arr.InsertAtEnd(value);
	}
	void Clear()
	{
		_Arr.Clear();
	}
};

