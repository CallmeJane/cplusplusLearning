#pragma once
#include<iostream>
int& func(int i)
{
	int temp = 10;		//因为还有temp的引用，所以还没有被销毁
	temp = temp + i;
	return temp;
}
//使用malloc和new来申请数组空间
char* func1()
{
	//char* p = (char*)malloc(100);		//申请100个空间
	char *p = new char[100]();			//new一个数组类型，空间大小时100
	//sizeof(*p)=1(char的大小),sizeof(p)=4(指针的大小)
	memset(p, 0, _msize(p));
	std::cout << "sizeop=" << sizeof(*p)<<std::endl;
	std::cout << "p=" << _msize(p) << std::endl;
	p[0] = '1';
	delete p;
	//p[0] = '1';			//此时调用会出错，因为以已经将空间释放了
	return p;
}


