#pragma once
#include<deque>
#include<iostream>

using std::deque;
using std::cout;
using std::endl;

/*
	deque：双端队列(类似vector可以从两头和中间插入操作，都很快)
	采用分块（每块512byte）线性队列进行管理，map记录每一块的起始位置，
	对每一块的操作，不影响其他部分

	当考虑内存的分配策略和性能时，deque的性能会比vector要好
*/
void deque_push_pop()
{
	deque<int> d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);

	d.push_front(4);
	d.push_front(5);

	d.insert(d.begin() + 1, 10);

	d.pop_back();
	d.pop_front();
	d.erase(d.begin() + 1);
}

