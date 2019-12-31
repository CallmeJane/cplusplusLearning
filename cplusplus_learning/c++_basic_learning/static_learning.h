#pragma once
#include<iostream>

int func1(int i)
{
	static int t = i;
	std::cout << "&t=" << &t << "\n";
	return t;
}

void static_learning_main()
{
	int i = func1(10);
	i = func1(20);
}