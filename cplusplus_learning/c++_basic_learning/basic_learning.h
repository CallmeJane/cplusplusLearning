#pragma once
#include<iostream>
int& func(int i)
{
	int temp = 10;		//��Ϊ����temp�����ã����Ի�û�б�����
	temp = temp + i;
	return temp;
}
//ʹ��malloc��new����������ռ�
char* func1()
{
	//char* p = (char*)malloc(100);		//����100���ռ�
	char *p = new char[100]();			//newһ���������ͣ��ռ��Сʱ100
	//sizeof(*p)=1(char�Ĵ�С),sizeof(p)=4(ָ��Ĵ�С)
	memset(p, 0, _msize(p));
	std::cout << "sizeop=" << sizeof(*p)<<std::endl;
	std::cout << "p=" << _msize(p) << std::endl;
	p[0] = '1';
	delete p;
	//p[0] = '1';			//��ʱ���û������Ϊ���Ѿ����ռ��ͷ���
	return p;
}


