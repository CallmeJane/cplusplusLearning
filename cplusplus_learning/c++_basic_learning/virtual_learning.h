#pragma once
#include<iostream>
//虚函数
//纯虚函数：带有纯虚函数的类不能实例化。因为有些类是不适合有实例的，eg:animal实例化
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
		//类中有虚函数指针
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
		//子类中是虚函数
		std::cout << "class B\n";
	}
	void print1()
	{
		//重写A的print1
		std::cout << "1 class B\n";
	}
};

void virtual_learning_main()
{
	//使用B的实例来给A的实例赋值
	//A a = B();
	//a.print();

	//多态的的实现,重写普通函数不能实现多态
	A* b1 = new B();
	A* a1 = new A();
	a1->print();
	a1->print1();
	b1->print();
	b1->print1();
	std::cin.get();
}
