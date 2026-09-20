#pragma once
#include "clsMyQueue.h"
template <class T>
class clsStack : public clsMyQueue<T>
{
public:
	void push(T value)
	{
		clsMyQueue <T>::_List.InsertAtFirst(value);
	}
	T top()
	{
		return clsMyQueue<T>::front();
	}
	T bottom()
	{
		return clsMyQueue<T>::back();
	}
};

