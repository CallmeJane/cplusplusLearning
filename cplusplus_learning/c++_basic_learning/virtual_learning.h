#pragma once
#include<iostream>
//�麯��
//���麯�������д��麯�����಻��ʵ��������Ϊ��Щ���ǲ��ʺ���ʵ���ģ�eg:animalʵ����
class Animal {

	void eat() {}
	virtual void future()=0;
};

class A {
public:
	A()
	{
		std::cout << "struct A\n";
	}
	virtual void print() {
		//�������麯��ָ��
		std::cout << "class A\n";
	}
	void print1()
	{
		std::cout << "1 class A\n";
	}
};
class B :public A {
	
public:
	B()
	{
		std::cout << "struct B\n";
	}
	void print()
	{
		//���������麯��
		std::cout << "class B\n";
	}
	void print1()
	{
		//��дA��print1
		std::cout << "1 class B\n";
	}
};

void virtual_learning_main()
{
	//ʹ��B��ʵ������A��ʵ����ֵ
	//A a = B();
	//a.print();

	//��̬�ĵ�ʵ��,��д��ͨ��������ʵ�ֶ�̬
	A* b1 = new B();
	A* a1 = new A();
	a1->print();
	a1->print1();
	b1->print();
	b1->print1();
	std::cin.get();
}
