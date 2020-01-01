#pragma once
#include<deque>
#include<iostream>

using std::deque;
using std::cout;
using std::endl;

/*
	deque��˫�˶���(����vector���Դ���ͷ���м������������ܿ�)
	���÷ֿ飨ÿ��512byte�����Զ��н��й���map��¼ÿһ�����ʼλ�ã�
	��ÿһ��Ĳ�������Ӱ����������

	�������ڴ�ķ�����Ժ�����ʱ��deque�����ܻ��vectorҪ��
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

