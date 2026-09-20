#pragma once
#include "clsMyQueueArr.h"
template <class T>
class clsStackArr : public clsMyQueueArr<T>
{
public:
	void push(T value)
	{
		clsMyQueueArr <T>::_Arr.InsertAtFirst(value);
	}
	T top()
	{
		return clsMyQueueArr<T>::front();
	}
	T bottom()
	{
		return clsMyQueueArr<T>::back();
	}
};