#pragma once
#include <map>
#include <string>
#include <iostream>
#include<unordered_map> //hash
#include <functional>

using std::cout;
using std::endl;
using std::string;
using std::map;

/*
	map��insert��key�ǰ��մ�С��������ģ���keyһ��Ҫ����<�����

	map��key-value��ӳ��ʹ�õ��Ǻ����

	map��Ӧ�ã�
	��1��ͳ��ÿ�����ʵĳ��ִ���
	��2�����ڲ������Žϸߵ�Ҫ��
*/
//map����ɾ�Ĳ���ص�
//insert 4�֣�ɾ��1�֣��޸�2�У�����2��
void map_iecs()
{
	//insert
	map<string, int> m;
	m.insert(std::make_pair("123", 1));
	m.insert(std::pair<string, int>("234", 2));
	m.insert(map<string,int>::value_type("345", 3));
	m["aaa"] = 4;

	//erease
	int n = m.erase("aaa");			//����ɾ����Ԫ�ظ���

	//update
	m["123"] = 100;
	map<string, int>::iterator iter = m.begin();
	iter->second = 10;

	//search
	auto i = m["234"];				//���ǲ��ҵ�ֵ�����ڣ�����0����ȱ��
	auto ret = m.find("123");
	if (ret != m.end())
		cout << "δ�ҵ�" << endl;
}

//�Զ���map������ʽ����ͨ���ͻ��߽ṹ�壩
struct myComp
{
	bool operator()(const int&a,const int&b)
	{
		return a > b;
	}
};

struct Info
{
	float score;
	string name;
	bool operator<(Info a) const
	{
		return score < a.score;
	}
};
void map_named_sort()
{
	map<int, string, myComp> m;
	m.insert(std::pair<int, string>(1, "111"));
	m.insert(std::pair<int, string>(2, "222"));
	m.insert(std::pair<int, string>(3, "333"));

	map<Info, int> m_info;
	Info info;
	info.name = "aaa";
	info.score = 1.1;
	m_info.insert(std::pair<Info, int>(info, 1));
	info.name = "bbb";
	info.score = 2.2;
	m_info.insert(std::pair<Info, int>(info, 2));
	info.name = "ccc";
	info.score = 3.3;
	m_info.insert(std::pair<Info, int>(info, 3));
}

//string��int��ת��������map����������ȻҲ������������Ĺ�ϵ��
//��������̫��ʱ����������һһӳ���ϵ

/*
	hash_map:������string/�Զ���������keyʱ������������ʹ��unordered_map
*/
struct Person
{
	int age;
	string name;
	Person(string _n,int _a)
	{
		name = _n;
		age = _a;
	}
	//��unordered_map��key��structʱ����Ҫ����==��ʵ��hash_value
	bool operator==(const Person& per) const
	{
		return per.age == age && per.name == name;
	}
};

size_t hash_value(const Person& per)
{
	return std::hash<string>()(per.name) ^ std::hash<int>()(per.age);
}

void unordered_map_named_test()
{
	std::unordered_map<Person, int,std::function<size_t(const Person&)>> m(100,hash_value);
	m[Person("Mark", 19)] = 19;
	m[Person("Jane", 23)] = 23;
}