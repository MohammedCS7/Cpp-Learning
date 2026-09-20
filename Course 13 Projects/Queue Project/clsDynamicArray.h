#pragma once
#include <iostream>
using namespace std;
template <class T>
class clsDynamicArray
{
protected:
	T* _TempArray;
	T* _Array;
	int _Size;
public:
	clsDynamicArray()
	{
		_Size = 0;
		_Array = new T[0];
	}
	clsDynamicArray(int size)
	{
		if (size < 0)
			size = 0;
		_Array = new T[size];
		_Size = size;
	}

	~clsDynamicArray()
	{
		delete[] _Array;
	}

	bool SetItem(int index, T value)
	{
		if (index >= _Size || index < 0)
			return false;
		*(_Array + index) = value;
		return true;
	}
	bool Resize(int newSize)
	{
		if (newSize < 0)
			return false;

		if (newSize == _Size)
			return true;

		_TempArray = new T[newSize];

		int length = (newSize < _Size) ? newSize : _Size;

		for (int i = 0; i < length;i++)
		{
			_TempArray[i] = _Array[i];
		}

		delete[] _Array;
		_Array = _TempArray;
		_Size = newSize;

		return true;
	}
	T GetValue(int index)
	{
		if (index >= _Size || index < 0)
			return T();
		return _Array[index];
	}
	void Reverse()
	{
		int length = _Size - 1;
		if (_Size == 0 || _Size == 1)
			return;
		_TempArray = new T[_Size];
		for (int i = 0; i <= length; i++)
		{
			_TempArray[i] = _Array[length - i];
		}
		delete[] _Array;
		_Array = _TempArray;
	}
	bool Clear()
	{
		if (_Size == 0)
			return false;
		delete[] _Array;
		_Array = new T[0];
		_Size = 0;
		return true;
	}
	bool DeleteValue(int index)
	{
		if ( index < 0 || index >= _Size)
			return false;
		_Size--;
		_TempArray = new T[_Size];
		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = _Array[(i < index) ? i : i + 1];
		}
		delete[] _Array;

		_Array = _TempArray;
		return true;
	}
	bool DeleteFirst()
	{
		return DeleteValue(0);
	}
	bool DeleteLast()
	{
		return DeleteValue(_Size - 1);
	}
	int Find(T value)
	{
		for (int i = 0; i < _Size; i++)
		{
			if (_Array[i] == value)
				return i;
		}
		return -1;
	}
	bool DeleteByValue(T value)
	{
		int index = Find(value);
		if (index == -1)
			return false;
		return DeleteValue(index);
	}
	bool InsertAt(int index, T value)
	{
		if (index < 0 || index > _Size)
			return false;
		_Size++;
		T* temp = new T[_Size];
		for (int i = 0; i < _Size; i++)
		{
			if (i == index)
				temp[i] = value;
			else
				temp[i] = _Array[(i < index) ? i : i - 1];
		}
		delete[] _Array;
		_Array = temp;
		return true;
	}
	bool InsertAtFirst(T value)
	{
		return InsertAt(0, value);
	}
	bool InsertBefore(int index, T value)
	{
		return InsertAt(index - 1, value);
	}
	bool InsertAfter(int index, T value)
	{
		return InsertAt(index + 1, value);
	}
	bool InsertAtEnd(T value)
	{
		return InsertAt(_Size,value);
	}
	bool UpdateValue(int index, T newValue)
	{
		if (index < 0 || index >= _Size)
			return false;
		for (int i = 0; i < _Size; i++)
		{
			if (i == index)
			{
				_Array[i] = newValue;
				return true;
			}
		}
		return false;
	}
	bool IsEmpty()
	{
		return (_Size <= 0);
	}
	int Size()
	{
		return _Size;
	}
	void PrintList()
	{
		for (int i = 0; i < _Size; i++)
		{
			cout << *(_Array + i) << " ";
		}
		cout << "\n";
	}

};

