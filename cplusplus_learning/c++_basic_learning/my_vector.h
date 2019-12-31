#pragma once
//一步步构建自己的vector
#include<cassert>
#include<vector>
#include<iostream>
#include<algorithm>
using std::cout;

typedef unsigned int size_t;
//每个类的实现之前都要template
template<class T>
class MyVector
{
public:
	//属性
	typedef T * iterator;
	//函数
	MyVector();
	MyVector(int size, const T& a);		//size 个 a
	MyVector(const MyVector<T>& a);
	~MyVector();
	//只能自己的管理的私有属性
	size_t size() const;
	size_t cap() const;
	size_t max_cap() const;

	void push_back(const T& val);		//这里为什么用的是引用,引用意味着可以修改值
	void pop_back();

	T& operator[](int index);
	MyVector<T>& operator=(MyVector<T> a);
	bool empty() const;
	iterator begin() const;
	iterator end() const;

private:
	//私有属性：加_
	size_t _size;
	size_t _cap;
	T* _buf;
	const size_t _max_cap = 65536;

};

template<typename T>
MyVector<T>::MyVector()
{
	//现在可以放下一个元素，但是一个元素都没有
	_size = 0;
	_buf = new T[1];
	_cap = 1;
}

template<typename T>
MyVector<T>::MyVector(int size, const T& a)
{
	if (_max_cap < _size)
		_size = _max_cap;
	//cap!=size
	_size = size;
	_cap = 1;
	//注意cap的分配
	for (:_cap < _size : )
		_cap *= 2;
	//实际分配的是cap的大小
	_buf = new T[_cap];
	for (int i = 0; i < _size; i++)
	{
		_buf[i] = a;
	}
}

template<typename T>
//拷贝构造
MyVector<T>::MyVector(const MyVector<T>& a)
{
	//深拷贝，传&参数是怕误修改参数的值
	_size = a._size;
	_cap = a._cap;
	_buf = new T[_cap];
	for (int i = 0; i < _size; i++)
		_buf[i] = a._buf[i];
}
template<typename T>
MyVector<T>::~MyVector()
{
	delete[] _buf;
}

template<typename T>
size_t MyVector<T>::size() const
{
	//const属于函数的类型，即使参数类型，函数名字和返回值类型一致，函数类型不同，也不是一个函数
	return _size;
}

template<typename T>
size_t MyVector<T>::cap() const
{
	return _cap;
}

template<typename T>
size_t MyVector<T>::max_cap() const
{
	return _max_cap;
}

template<typename T>
void MyVector<T>::push_back(const T& val)
{
	if (_size + 1 < _cap)
	{
		_buf[_size] = val;
		_size++;
	}
	else
	{
		_cap = 2 * _cap;
		T* temp = new T[_cap];
		for (int i = 0; i < _size; i++)
			temp[i] = _buf[i];
		delete _buf;
		temp[_size] = val;
		_buf = temp;
		_size++;
	}
}

template<typename T>
void MyVector<T>::pop_back()
{
	if (_size > 0)
	{
		_buf[_size - 1] = 0;
		_size--;
	}
}

template<typename T>
T& MyVector<T>::operator[](int index)
{
	if (index < _size)
		return _buf[index];
	else
		return nullptr;
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(MyVector<T> vals)
{
	MyVector<T> temp;
	temp._size = vals._size;
	temp._cap = vals._cap;
	temp._buf = new T[temp._cap];
	for (int i = 0; i < size; i++)
	{
		temp._buf[i] = vals._buf[i];
	}
	return temp;
}

template<typename T>
bool MyVector<T>::empty() const
{
	if (_size > 0)
		return true;
	else
		return false;
}

template<typename T>
iterator MyVector<T>::begin() const
{
	return _buf;
}

template<typename T>
iterator MyVector<T>::end() const
{
	if (_size > 0)
		return _buf[size];
	else
		return _buf;
}

bool compare(const int& a, const int& b)
{
	//降序
	return a > b;
}

void vector_test()
{
	int count = 10;
	std::vector<int> v;
	v.reserve(count);
	for (int i = 0; i < count; i++)
		v.push_back(i);

	reverse(v.begin(), v.end());
	for (auto i : v)
		cout << " " << i;

	sort(v.begin(), v.end(), compare);
}
